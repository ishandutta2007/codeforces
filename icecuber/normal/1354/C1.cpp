#include <bits/stdc++.h>
using namespace std;
#include <string>
typedef long long ll;
//-Wfatal-errors
// node=vertex . edges connect vertices
//alias d++='g++ -std=c++17 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g '

struct s_ix {
  ll left, right, size;
};
bool operator<(s_ix  aa, s_ix  bb) {
  if(aa.size == bb.size)return aa.left>bb.left;
  return aa.size < bb.size;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll T;
  //next_permutation
  //set<ll> pos;
  //if(pos.count()>0){
  //  pos.insert(a);}
  //assert(true);//ok
  //assert(false);//fails
  //true=1 false=0
  //T=1;

  cin>>T;

  // for (int j=0;j<n;j++)a[j]=0;
  while(T--){
    ll n,m,k,y,a,b,c,d;
    string s;
    int sum=0;
    cin>>n;
    //for (int j=0;j<n;j++)cin>>a[j];
    //for (int j=0;j<n;j++){
    //}
    double aa=3.1415926535/(2*n);
    cout<< setprecision(8)<<1.0d/tan(aa)<<endl;
  }
}