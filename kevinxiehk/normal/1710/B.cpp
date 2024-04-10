#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
#define ick cout<<"ickbmi32.9\n"
using namespace std;
bool isprime(int k) {
    for(int i = 2; i <= sqrt(k); i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b, int mod) {
    if(b == 0) return 1;
    int t = bm(a, b / 2, mod); 
    t = t * t % mod; 
    return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) {return bm(a, mod - 2, mod);}
void gay(int TC) {cout << "Case #" << TC << ": ";}
struct rain{
    int x, p;
    int id;
    int acc = 0;
};
vector<rain> arr;
bool cmp(rain a, rain b) {
    return a.x < b.x;
}
bool cmp2(rain a, rain b) {
    return a.id < b.id;
}
void solve(int TC) {
    int n, m;
    cin >> n >> m;
    arr.clear();
    for(int i = 0; i < n; i++) {
        rain t;
        cin >> t.x >> t.p;
        t.id = i;
        arr.pb(t);
    }
    sort(arr.begin(), arr.end(), cmp);
    int curr = 0, cnt = 0;
    priority_queue<int, vector<int>, greater<>> die;
    for(int i = 0; i < n; i++) {
        while(cnt > 0 && die.top() <= arr[i].x) {
            curr -= die.top() - arr[i - 1].x;
            die.pop();
            cnt--;
        }
        if(i > 0) curr -= cnt * (arr[i].x - arr[i - 1].x);
        curr += arr[i].p;
        arr[i].acc += curr;
        cnt++;
        die.push(arr[i].p + arr[i].x);
    }

    // for(int i = 0; i < n; i++) cout << arr[i].x << ' ' << arr[i].acc << '\n';
    curr = 0, cnt = 0;
    priority_queue<int> die2;
    for(int i = n - 1; i >= 0; i--) {
        while(cnt > 0 && die2.top() >= arr[i].x) {
            curr -= -die2.top() + arr[i + 1].x;
            die2.pop();
            cnt--;
        }
        if(i < n - 1) curr -= cnt * abs(arr[i].x - arr[i + 1].x);
        arr[i].acc += curr;
        curr += arr[i].p;
        cnt++;
        die2.push(-arr[i].p + arr[i].x);
    }

    // for(int i = 0; i < n; i++) cout << arr[i].x << ' ' << arr[i].acc << '\n';

    int mincut = inf;
    int maxcut = -inf;

    for(int i = 0; i < n; i++) {
        if(arr[i].acc > m) {
            arr[i].acc -= m;
            maxcut = max(maxcut, arr[i].acc + arr[i].x);
            mincut = min(mincut, -arr[i].acc + arr[i].x);
        }
    }

    sort(arr.begin(), arr.end(), cmp2);

    for(int i = 0; i < n; i++) {
        if(arr[i].x - arr[i].p <= mincut && arr[i].x + arr[i].p >= maxcut) cout << '1';
        else cout << '0';
    }
    cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    //while(t--) solve();
    for(int i = 1; i <= t; i++) solve(i);
    return 0;
}