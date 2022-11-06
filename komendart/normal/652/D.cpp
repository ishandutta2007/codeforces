#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//ifstream fin ("input.txt");
//ofstream fout ("output.txt");

#define forn(i,n) for(int i = 0; i < n; ++i)
#define mp make_pair
#define pb push_back
#define all(t) t.begin(),t.end()
#define gcd(x,y) __gcd(x,y)

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N = 400000;
const int INF = (int)10e6;
const double eps = 10e-6;
const long long MOD = 1000000007;

pair< LL, pair<LL,LL> > a[N];
tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update> s;
int ans[N];
int n;

bool cmp(pair<LL,pair<LL,LL> > x, pair<LL,pair<LL,LL> > y){
    return x.second.second <= y.second.second;
}

int main(){
	std::ios::sync_with_stdio(false);
	//freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].second.first >> a[i].second.second;
        a[i].first = i;
    }
    sort(a, a + n,cmp);
    for(int i = 0; i < n; ++i){
        LL l = a[i].second.first;
        LL r = a[i].second.second;
        int ind = a[i].first;
        if(s.upper_bound(a[i].second.first) == s.end()){
            s.insert(a[i].second.first);
            continue;
        }
        else{
            int j = s.size() - s.order_of_key(a[i].second.first);
            s.insert(a[i].second.first);
            ans[a[i].first] = j;
        }
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << "\n";
	return 0;
}