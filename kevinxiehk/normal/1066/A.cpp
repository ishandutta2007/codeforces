#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
     cin>>t;
     while(t--){
          long long a,b,c,d;
          cin>>a>>b>>c>>d;
          cout<<a/b-d/b+(c-1)/b<<endl;
     }
     return 0;
}