#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

const ll BIG = 999999999999;
vector<int> nums;
map<int, int> ch, cl, cr, cL, cR;

class minSeg {
public:
    int size = 1;
    vector<int> nums;
    minSeg(int s) {
        while(size < s) size *= 2;
        size *= 2;
        size--;
        for(int i = 0; i <= size; i++) nums.push_back(BIG);
    }
    void set(int n, int x) {
        int i = size/2 + n;
        while(i > 0) {
            nums[i] = min(nums[i], x);
            i /= 2;
        }
    }
    int getMin(int l, int r, int n, int lx, int rx) {
        int a, b;
        if(l >= rx) return BIG;
        if(r <= lx) return BIG;
        if(rx == lx + 1) return nums[n];
        int mid = (lx+rx)/2;
        a = getMin(l, r, n*2, lx, mid);
        b = getMin(l, r, n*2+1, mid, rx);
        return min(a, b);
    }
    int getMin(int l, int r) {
        int x = getMin(l, r, 1, 1, (size+3)/2); return x;
    }
};

signed main() {
    int t;
    cin >> t;
    while(t--) {
        vector<int>().swap(nums);
        map<int, int>().swap(ch);
        map<int, int>().swap(cl);
        map<int, int>().swap(cr);
        map<int, int>().swap(cL);
        map<int, int>().swap(cR);
        int n, x, y, mL = -1, k = 0, a, b, c, l, r;
        bool sad = false;
        cin >> n;
        auto mS = new minSeg(n);
        for(int i = 0; i < n; i++) {
            cin >> x;
            nums.push_back(x);
            mS->set(i+1, x);
        }
        for(int i = 0; i < n; i++) {
            if(mL < nums[i]) {
                k = 0;
                mL = nums[i];
            }
            if(mL == nums[i]) {
                k++;
                if(k == 1) {
                    a = i+1;
                    l = i;
                    r = i;
                }
                if(k == 2) {
                    a = i;
                    b = 1;
                    c = n-i-1;
                    r = i;
                }
            }
            cL[i] = mL;
        }
        mL = -1;
        for(int i = n-1; i >= 0; i--) {
            mL = max(mL, nums[i]);
            cR[i] = mL;
        }
        if(k >= 3) {
            cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
            continue;
        }
        else {
            int M = BIG;
            for(int i = l; i <= r; i++) {
                M = min(M, nums[i]);
            }
            while(true) {
            int s = r + l;
            //cout << l << cL[l-1] << r << cR[r+1] << '*';
            if(M == cL[l-1] && M == cR[r+1]) {
                cout << "YES\n" << l << ' ' << r-l+1 << ' ' << n-r-1 << '\n'; 
                sad = true;
                break;
            }
            if(l <= 1 && r >= n-1) break;
            else if(l <= 1) r++;
            else if(r >= n-1) l--;
            else if(min(cL[l-2], min(min(M, nums[l-1]), cR[r+1])) > min(cL[l-1], min(min(M, nums[r+1]), cR[r+2]))) l--;
            else r++;
            if(r + l > s) M = min(M, nums[r]);
            else M = min(M, nums[l]);
            if(M == cL[l-1] && M == cR[r+1]) {
                cout << "YES\n" << l << ' ' << r-l+1 << ' ' << n-r-1 << '\n'; 
                sad = true;
                break;
            }
            }
        }
        if(!sad) cout << "NO\n";
    }
}