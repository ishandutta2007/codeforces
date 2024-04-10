#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+10;
int z[mn];
int psa[mn];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    string s;
    cin>>s;
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(r<i){
            l=r=i;
            while(r<n&&s[r]==s[r-l])r++;
            z[i]=r-l;
        }
        else{
            int d=i-l;
            if(z[d]<r-i)z[i]=z[d];
            else{
                l=i;
                while(r<n&&s[r]==s[r-l])r++;
                z[i]=r-l;
            }
        }
    }
    z[0]=n;
    for(int len=1;1LL*len*k<=n;len++){
        bool hail=0;
        for(int i=0;i<k;i++)if(z[len*i]<len)hail=1;
        int num=min(z[len*k],len);
        if(!hail) {
            psa[len * k-1]++;
            psa[num + len * k]--;
        }
    }
    for(int i=1;i<=n;i++)psa[i]+=psa[i-1];
    for(int i=0;i<n;i++)printf("%d",(psa[i]>=1));
}