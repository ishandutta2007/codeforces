#include<stdio.h>
#include<set>
using namespace std;
set<long long> st;
long long n,ans=1;

int main(){
    scanf("%I64d",&n);
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            st.insert(i);
            while(n%i==0)n/=i;
        }
        if(n==1)break;
    }
    st.insert(n);
    for(set<long long>::iterator it=st.begin();it!=st.end();it++)ans*=*it;
    printf("%I64d",ans);
}