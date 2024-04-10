#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define sqr(x) ((x) * 1LL * (x))
#define vl vector <long long>
#define pll pair<long long , long long>
#define mp make_pair
#define F first
#define S second
#define fast_io ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int inf = 1e6;
int main() 
{
 int n , k , n1;
 unsigned int ans = 0;
 cin>>n>>k;
 vl res;
 n1 = n;
 if (k == 0 && n == 2){ cout<<"NO"; return 0;}
 if (n == 2) {cout<<"YES"<<endl<<"0 "<<k; return 0;}
 if (n == 1) {cout<<"YES"<<endl<<k; return 0;}
 cout<<"YES"<<endl;

 for(int i = 1; i <= n-3; i++){
 cout<<i<<" ";
  k ^= i;
  
 }
int p18 = 1 << 18;
int p17 = 1 << 17;
    cout << (p18 ^ p17 ^ k) << ' ' << p18 << ' ' << p17 << endl;
 return 0;
}