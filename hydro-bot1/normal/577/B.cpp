// Hydro submission #619f0762f9c5be5363bb63b5@1637812066623
#include<bits/stdc++.h>
using namespace std;
bitset<1001>f;
int main(){
 int n,m,i;
 for(cin>>n>>m,f.set(0);n--;f|=f<<i%m|f>>(m-i%m))if(cin>>i,i%m==0)cout<<"YES\n",exit(0);
 cout<<(f.test(m)?"YES":"NO")<<'\n';
}