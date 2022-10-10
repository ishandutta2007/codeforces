#include<bits/stdc++.h>
using namespace std;
int n,k;
int s[1000010],l=1,r;
map<int,int>M;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(!M[x]){
            s[++r]=x;
            M[x]=r;
            if(r-l==k){
                M[s[l]]=0;
                l++;
            }
        }
    }
    cout<<r-l+1<<endl;
    for(int i=r;i>=l;i--)cout<<s[i]<<' ';
}