#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;cin>>t;
  while(t--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    printf("%d\n",max(a-c,c-1)+max(b-d,d-1));
  }
}