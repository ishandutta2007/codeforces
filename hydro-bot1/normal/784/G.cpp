// Hydro submission #62fe53413731a6f56a42f2b6@1660834625898
#include<bits/stdc++.h>
using namespace std;
string operator*(string s,unsigned a){
    string res="";
    while(a--)res+=s;
    return res;
}
int main(){
    int x,ans=0;
    while(cin>>x)ans+=x;
    string add="+";
    int a=ans/100,b=ans/10%10,c=ans%10;
    if(ans>99)cout<<add*(a+48u)<<".>";
    if(ans>9)cout<<add*(b+48u)<<".>";
    cout<<add*(c+48u)<<'.';
}