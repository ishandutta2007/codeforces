#include <bits/stdc++.h>
using namespace std;

const int SS = (1e5)+4;
int k, N;
char s[SS];
int cnt1[30], cnt2[30];
int ans[5];
int whe[5];

int main(){
//    freopen("input.txt", "r", stdin);

    scanf("%d", &k);
    for(int a=1;a<=3;a++){
        scanf("%s", s);
        for(int i=0;i<30;i++) cnt1[i] = cnt2[i] = 0;
        N = strlen(s);
        for(int i=0;i<N;i++) s[i]>='A'&&s[i]<='Z'? cnt1[s[i]-'A']++:cnt2[s[i]-'a']++;
        for(int i=0;i<30;i++){
            if(k==1&&cnt1[i]==N) ans[a] = max(ans[a], N-1);
            else ans[a] = max(ans[a], min(N, cnt1[i]+k));
        }
        for(int i=0;i<30;i++){
            if(k==1&&cnt2[i]==N) ans[a] = max(ans[a], N-1);
            else ans[a] = max(ans[a], min(N, cnt2[i]+k));
        }
        whe[a] = ans[a];
    }
    for(int i=1;i<=2;i++) for(int j=i+1;j<=3;j++) if(ans[i]>ans[j]) swap(ans[i], ans[j]);
    if(ans[3]!=ans[2]){
        if(whe[1]==ans[3]) puts("Kuro");
        if(whe[2]==ans[3]) puts("Shiro");
        if(whe[3]==ans[3]) puts("Katie");
    }
    else puts("Draw");

    return 0;
}