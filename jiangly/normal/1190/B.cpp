// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
void A(){
    cout<<"sjfnb"<<endl;
    exit(0);
}
void B(){
    cout<<"cslnb"<<endl;
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(n==1){
        if(a[0]%2==0){
            B();
        }else{
            A();
        }
    }
    if(a[1]==0){
        B();
    }
    vector<int> b=a;
    if(unique(b.begin(),b.end())-b.begin()<=n-2){
        B();
    }
    int t=0;
    for(int i=0;i<n-1;++i){
        if(a[i]==a[i+1]){
            if(i>0&&a[i-1]==a[i]-1){
                B();
            }
            --a[i];
            t=1;
        }
    }
    for(int i=0;i<n;++i){
        t=(t+a[i]-i)%2;
    }
    if(t%2==0){
        B();
    }else{
        A();
    }
    return 0;
}