// Hydro submission #62cd07dc4125dc528b1ce1be@1657604061060
#include<bits/stdc++.h>
using namespace std;
string str[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int main(){
    string in;
    cin>>in;
    int num;
    cin>>num;
    int ans=abs(distance(find(str,str+12,in),str));
    if(ans+num>=12) cout<<str[(ans+num)%12];
    else cout<<str[ans+num];
    return 0;
}