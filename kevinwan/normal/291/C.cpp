#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e5+10;
unsigned int num[mn];
int main(){
    unsigned int n,k,a,b,c,d,i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%u.%u.%u.%u",&a,&b,&c,&d);
        num[i]=(a<<24)|(b<<16)|(c<<8)|d;
    }
    sort(num,num+n);
    for(j=0;j<n;j++)num[j]>>=1;
    int bes=-1;
    for(i=1;i<32;i++){
        int uni=1;
        for(j=1;j<n;j++)if(num[j]!=num[j-1])uni++;
        if(uni==k){
            bes=i;
        }
        for(j=0;j<n;j++)num[j]>>=1;
    }
    if(bes==-1){
        printf("-1");
        return 0;
    }
   unsigned int ans=-(1<<bes);
    printf("%u.%u.%u.%u",(ans>>24)&255,(ans>>16)&255,(ans>>8)&255,ans&255);
}