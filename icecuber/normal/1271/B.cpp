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

/*string swaps(string str,ll index,ll n){
  if (str[index] == 'W') {
  str[index] = 'B';
  }
  else
  str[index] = 'W';
  if(str[index+1] == 'W') {
  str[index+1] = 'B';
  }
  else
  str[index+1] = 'W';
  return str;
  }

  bool pairs(string str,ll index,ll n){
  bool ans = true;
  swaps(str, index, n);
  for (int i = index + 1; i < n - 2;i++) {
  if (str[i + 1] == str[i + 2]);
  else{
  ans = false;
  }
  }
  return ans;
  }			fori(n) {
  if (pairs(str, i, n)) {
  str = swaps(str, i, n);
  operations++;
  indexes.pb(i);
  for (int j = i + 1; j < n - 1; j += 2) {
  if (str[j] == str[j + 1]) {
  str = swaps(str, j, n);
  operations++;
  indexes.pb(j);
  }
  }
  }
  }
  }
  cout << operations << endl;
  trav(indexes){
  cout << i << " ";
  }*/

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
#if defined _MSC_VER
  freopen("Text.txt", "r", stdin);//read all input form this local file
#endif
  ll n;
  cin >> n;
  string str;
  ll w = 0, b = 0;
  vll indexes;
  ll operations = 0;
  fori(n) {
    char a;
    cin >> a;
    if (a == 'W')
      w++;
    if (a == 'B')
      b++;
    str += a;
  }
  if (w % 2 && b % 2)
    operations = -1;
  else if (w == n || b == n);
  else if ((w % 2 == 0 && b % 2) || (w % 2 == 0 && b < w)) { //Fix
    forj(3) {
      bool noswap = 1;
      fori(n - 1) {
	if (str[i] == 'W'&&str[i + 1] == 'W') {
	  noswap = 0;
	  operations++;
	  indexes.pb(i+1);
	  str[i] = 'B';
	  str[i + 1] = 'B';
	}
	//}
	//fori(n - 1) {
	noswap = 0;
	if (str[i] == 'W'&&str[i + 1] == 'B') {
	  operations++;
	  indexes.pb(i+1);
	  swap(str[i], str[i + 1]);
	}
      }
      if (noswap)
	break;
    }
  }
  else {
    forj(3) {
      fori(n - 1) {
	if (str[i] == 'B'&&str[i + 1] == 'B') {
	  operations++;
	  indexes.pb(i+1);
	  str[i] = 'W';
	  str[i + 1] = 'W';
	}
	//}
	//fori(n - 1) {
	if (str[i] == 'B'&&str[i + 1] == 'W') {
	  operations++;
	  indexes.pb(i+1);
	  swap(str[i], str[i + 1]);
	}
      }
    }
  }
  cout << operations << endl;
  trav(indexes) {
    cout << i << " ";
  }
}