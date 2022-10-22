#include<bits/stdc++.h>
using namespace std;
int cnt[26];
int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        string s,t;
        cin>>s>>t;
        int ans=0;
        for(char c:s)cnt[c-'a']++;
        for(char c:t)cnt[c-'a']--;
        for(int i=0;i<26;i++){
            if(cnt[i]){
                printf("NO\n");
                goto veshy;
            }
        }
        for(char c:s)cnt[c-'a']++;
        for(int i=0;i<26;i++){
            if(cnt[i]>1){
                printf("YES\n");
                goto veshy;
            }
        }

        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
            if(s[i]>s[j])ans^=1;
            if(t[i]>t[j])ans^=1;
        }
        printf("%s\n",ans?"NO":"YES");
        veshy:
        int dta=0;
    }
}