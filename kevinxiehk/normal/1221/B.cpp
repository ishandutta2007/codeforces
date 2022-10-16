#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if((i+j)%2==0)cout<<'W';
            else cout<<'B';
        }
        cout<<endl;
    }
    return 0;
}