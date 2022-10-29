///
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int inf=0x3f3f3f3f,N=2e5+5;

int a[30];
char s1[N],s2[N];

int main(){
    #ifdef ONLINE_JUDGE
        //std::ios::sync_with_stdio(false);
    #else
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    while(n--){
        memset(a,0,sizeof(a));
        scanf("%s%s",s1,s2);
        int n1=strlen(s1),n2=strlen(s2);
        for(int i=0;i<n2;i++){
            a[s2[i]-'A']++;
        }
        for(int i=n1-1;i>=0;i--){
            if(a[s1[i]-'A']){
                a[s1[i]-'A']--;
            }
            else s1[i]='#';
        }
        int pos=0;
        for(int i=0;i<n1;i++){
            if(s2[pos]==s1[i])pos++;
        }
        printf(pos==n2?"YES\n":"NO\n");
    }
    return 0;
}