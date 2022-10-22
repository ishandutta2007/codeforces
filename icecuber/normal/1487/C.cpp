#include <bits/stdc++.h>
using namespace std;
#include <string>
typedef long long ll;
//-Wfatal-errors
// node=vertex . edges connect vertices
//alias d++='g++ -std=c++17 -Wshadow -Wall -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g '
//const double PI=acos(-1.0);
//cout << setprecision(20) << x << endl;

struct s_ix {
  ll t,ix,b;
};
bool operator<(s_ix  aa, s_ix  bb) {
  if(aa.t == bb.t) return aa.b > bb.b;
  return aa.t < bb.t;
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

  //T=1;
  cin>>T;

  // for (int j=0;j<n;j++)a[j]=0;
  while(T--){
    ll n,k;
    cin>>n;
    vector<vector<int>> ans(n, vector<int>(n));
    if(n%2==1){
      for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
          ans[i][j] = (i+j)%2 ? 1 : -1;
          //if((i+j)%2)cout<<1<<" ";
          //else cout<<-1<<" ";
        }
      }
    }else{
      for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
          if(2*(i-j)==n){
            //cout<<0<<" ";
          }else {
            if(2*(i-j)<n){
              ans[i][j] = (i+j)%2 ? 1 : -1;
              //if((i+j)%2)cout<<1<<" ";
              //else cout<<-1<<endl;
            }else{
              ans[i][j] = (i+j)%2 ? -1 : 1;
              //if((i+j)%2)cout<<-1<<" ";
              //else cout<<1<<" ";
            }
          }
        }
      }
    }
    int score[] = {0,1,3};
    vector<int> sum(n);
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        cout << ans[j][i] << ' ';
        sum[i] += score[ans[j][i]+1];
        sum[j] += score[-ans[j][i]+1];
      }
    }
    cout<<endl;
    for (int i = 0; i < n; i++) 
      assert(sum[i] == sum[0]);
  }
}