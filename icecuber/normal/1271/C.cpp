#if defined _MSC_VER //if using Visual Studio
#include "std_lib_facilities.h" //include this local header file
#else
#include<bits/stdc++.h> //include this non portable headerfile
using namespace std; //and the standard namespace
#endif
#pragma warning(disable:4996)//necessary if we want to use freopen()

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vld = vector<ld>;
using pll = pair<ll, ll>;
using vpl = vector<pll>;
using vpd = vector<pair<ld, ld>>;

#define dx first
#define dy second
#define forx(n) for (ll x=1;x<=n;x++)
#define fory(n) for (ll y=1;y<=n;y++)
#define rall(v) (v).rbegin(),(v).rend()
#define all(v) (v).begin(),(v).end()
#define fork(n) for (ll k=0;k<n;k++)
#define forj(n) for (ll j=0;j<n;j++)
#define fori(n) for (ll i=0;i<n;i++)
#define in() ll t; cin >> t; while(t--)
#define fin() ll n; cin >> n; fori(n)
#define trav(v) for(auto &i:v)
#define pb(x) push_back(x)

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER
  freopen("Text.txt", "r", stdin);//read all input form this local file
#endif
  ll n, sx, sy;
  cin >> n >> sx >> sy;
  ll underleft = 0, underright = 0, overleft = 0, overright = 0;
  ll x, y;
  ll over=0, under=0, left=0, right=0;
  fori(n) {
    cin >> x >> y;
    if (x < sx&&y < sy) {
      underleft++;
    }
    else if (x > sx&&y < sy) {
      underright++;
    }
    else if (x == sx && y < sy) {
      under++;
    }
    else if (x<sx&&y>sy) {
      overleft++;
    }
    else if (x > sx&&y > sy) {
      overright++;
    }
    else if (x == sx && y > sy) {
      over++;
    }
    else if (x < sx&&y == sy) {
      left++;
    }
    if (x > sx&&y == sy) {
      right++;
    }
  }
  over += overleft + overright;
  left += overleft + underleft;
  right += overright + underright;
  under += underright + underleft;
  if(over>= left&&over>=right&&over>=under&&sy+1<=1e9){//Fixed
    cout << over << endl;
    cout << sx << " " << sy+1;
  }
  else if(left>= over&&left>=right&&left>=under&&sx-1>=0){
    cout << left << endl;
    cout << sx - 1 << " " << sy;
  }
  else if(right>= over&&right>=left&&right>=under&&sx+1<=1e9){
    cout << right << endl;
    cout << sx + 1 << " " << sy;
  }
  else if(under>=right&&under>=over&&under>=left&&sy-1>=0){
    cout << under<<endl;
    cout << sx << " " << sy - 1; //Fixed
  }
}