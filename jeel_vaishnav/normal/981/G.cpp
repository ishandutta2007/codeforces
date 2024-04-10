#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const int N = 200000;
#define pb push_back
#define L LL;

long long segTree[4 * N], lazyAdd[4 * N], lazyMul[4 * N]; 
map<int, int> rangeMap[N + 1];

void computeLazy(int low, int high, int pos) {
    segTree[pos] = (segTree[pos] * lazyMul[pos] % mod + lazyAdd[pos] * (long)(high - low + 1) % mod) % mod;

    if(low != high) {
        int mid = (low + high) >> 1;
        lazyMul[2 * pos + 1] = lazyMul[2 * pos + 1] * lazyMul[pos] % mod;
        lazyMul[2 * pos + 2] = lazyMul[2 * pos + 2] * lazyMul[pos] % mod;
        lazyAdd[2 * pos + 1] = lazyAdd[2 * pos + 1] * lazyMul[pos] % mod;
        lazyAdd[2 * pos + 2] = lazyAdd[2 * pos + 2] * lazyMul[pos] % mod;
        lazyAdd[2 * pos + 1] = (lazyAdd[2 * pos + 1] + lazyAdd[pos]) % mod;
        lazyAdd[2 * pos + 2] = (lazyAdd[2 * pos + 2] + lazyAdd[pos]) % mod;
    }
    lazyMul[pos] = 1L;
    lazyAdd[pos] = 0L;
}

void updateSegTreeMul(int low, int high, int pos, int l, int r) {
    computeLazy(low, high, pos);

    if(low > r || high < l)
        return;
    if(low >= l && high <= r) {
        lazyMul[pos] = lazyMul[pos] * 2L % mod;
        computeLazy(low, high, pos);
        return;
    }

    int mid = (low + high) >> 1;
    updateSegTreeMul(low, mid, 2 * pos + 1, l, r);
    updateSegTreeMul(mid + 1, high, 2 * pos + 2, l, r);

    segTree[pos] = (segTree[2 * pos + 1] + segTree[2 * pos + 2]) % mod;
}

void updateSegTreeAdd(int low, int high, int pos, int l, int r) {
    computeLazy(low, high, pos);

    if(low > r || high < l)
        return;
    if(low >= l && high <= r) {
        lazyAdd[pos] = (lazyAdd[pos] + 1L) % mod;
        computeLazy(low, high, pos);
        return;
    }

    int mid = (low + high) >> 1;
    updateSegTreeAdd(low, mid, 2 * pos + 1, l, r);
    updateSegTreeAdd(mid + 1, high, 2 * pos + 2, l, r);

    segTree[pos] = (segTree[2 * pos + 1] + segTree[2 * pos + 2]) % mod;
}

long long querySegTree(int low, int high, int pos, int l, int r) {
    computeLazy(low, high, pos);

    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return segTree[pos];
    int mid = (low + high) >> 1;
    long ans1 = querySegTree(low, mid, 2 * pos + 1, l, r);
    long ans2 = querySegTree(mid + 1, high, 2 * pos + 2, l, r);
    return (ans1 + ans2) % mod;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < 4 * n; ++i) {
        segTree[i] = 0L;
        lazyAdd[i] = 0L;
        lazyMul[i] = 1L;
    }

    int type;
    for(int p = 0; p < q; ++p) {
        cin >> type;

        if(type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;

            int tempL = l;
            int lowerLimit = l;

            auto it = rangeMap[x].lower_bound(tempL);
            if(it != rangeMap[x].begin()) { 
                it--;
                if(rangeMap[x][it -> first] >= l) {
                    lowerLimit = it -> first;
                    if(rangeMap[x][lowerLimit] >= r) {
                        updateSegTreeMul(0, n - 1, 0, l, r);
                        tempL = r + 1;
                    }
                    else {
                        updateSegTreeMul(0, n - 1, 0, l, rangeMap[x][lowerLimit]);
                        tempL = rangeMap[x][lowerLimit] + 1;
                    }
                }
            }

            while(tempL <= r) {
                if(rangeMap[x].lower_bound(tempL) == rangeMap[x].end() || rangeMap[x].lower_bound(tempL)->first > r) {
                    updateSegTreeAdd(0, n - 1, 0, tempL, r);
                    tempL = r + 1;
                }
                else if(rangeMap[x].lower_bound(tempL)->first == tempL) {
                    if(rangeMap[x][tempL] <= r) {
                        updateSegTreeMul(0, n - 1, 0, tempL, rangeMap[x][tempL]);
                        tempL = rangeMap[x][tempL] + 1;
                    }
                    else {
                        updateSegTreeMul(0, n - 1, 0, tempL, r);
                        tempL = r + 1;
                    }
                }
                else {
                    updateSegTreeAdd(0, n - 1, 0, tempL, rangeMap[x].lower_bound(tempL)->first - 1);
                    tempL = rangeMap[x].lower_bound(tempL)->first;
                }
            }

            int upperLimit = r;
            while(rangeMap[x].lower_bound(lowerLimit) != rangeMap[x].end() && rangeMap[x].lower_bound(lowerLimit)->first <= r) {
                upperLimit = max(upperLimit, rangeMap[x][rangeMap[x].lower_bound(lowerLimit)->first]);
                rangeMap[x].erase(rangeMap[x].lower_bound(lowerLimit));
            }
            rangeMap[x][lowerLimit] = upperLimit;
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << querySegTree(0, n - 1, 0, l, r) << "\n";
        }
    }

    return 0;
}