// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>x;
    if(x%4==2){
        cout<<"1 B"<<endl;
    }else{
        cout<<(1-x%4+4)%4<<" A"<<endl;
    }
    return 0;
}