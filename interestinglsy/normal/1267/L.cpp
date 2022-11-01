#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1005;

int n,m,k;
char c[maxn*maxn];
int cnt[maxn];
int tmp[maxn];

int ans[maxn];
string st[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    cin>>c;
    int g=strlen(c);
    for(int i=0;i<g;i++){cnt[c[i]-'a']++;}
    for(int i=1;i<=m;i++){
        for(int c=0;c<26;c++){
            if(cnt[c]!=0){
                ans[i]=c;
                for(int i=0;i<26;i++)tmp[i]=cnt[i];
                tmp[c]--;
                int trg=k-1;
                bool ok=1;
                int lp=0;
                for(int j=1;j<=i;j++){
                    int less=0,eql=tmp[ans[j]];
                    if(ans[j]<lp)eql=0;
                    for(int i=lp;i<ans[j];i++)less+=tmp[i];
                    if(less>=trg)break;
                    else if(less+eql<trg){
                        ok=0;break;
                    }else{
                        trg-=less;
                        lp=max(lp,ans[j]);
                        tmp[ans[j]]-=trg;
                    }
                }
                for(int j=0;j<lp;j++)tmp[j]=0;
                lp=25;
                trg=n-k;
                for(int j=1;j<=i;j++){
                    int less=0,eql=tmp[ans[j]];
                    if(ans[j]>lp)eql=0;
                    for(int i=lp;i>ans[j];i--)less+=tmp[i];
                    if(less>=trg)break;
                    else if(less+eql<trg){
                        ok=0;break;
                    }else{
                        trg-=less;
                        lp=min(lp,ans[j]);
                        tmp[ans[j]]-=trg;
                    }
                }
                if(ok){
                    cnt[c]--;break;
                }
            }
        }
    }
    int trg=k-1;
    for(int i=1;i<=m;i++){
        int less=0,eql=cnt[ans[i]];
        for(int j=0;j<ans[i];j++)less+=cnt[j];
        int cp=0;
        for(int j=trg;j>=1;j--){
            while(cnt[cp]==0&&cp<26)cp++;
            if(cp>=ans[i])break;
            st[j].push_back(cp+'a');
            cnt[cp]--;
        }
        if(less>=trg){
            break;
        }else{
            trg-=less;
            for(int j=1;j<=trg;j++)st[j].push_back(ans[i]+'a');
            cnt[ans[i]]-=trg;
        }
    }
    int rtrg=n-k;
    for(int i=1;i<=m;i++){
        int less=0,eql=cnt[ans[i]];
        for(int j=ans[i]+1;j<26;j++)less+=cnt[j];
        int cp=25;
        for(int j=n-rtrg+1;j<=n;j++){
            while(cnt[cp]==0&&cp>=0)cp--;
            if(cp<=ans[i])break;
            st[j].push_back(cp+'a');
            cnt[cp]--;
        }
        if(less>=rtrg){
            break;
        }else{
            rtrg-=less;
            for(int j=n-rtrg+1;j<=n;j++)st[j].push_back(ans[i]+'a');
            cnt[ans[i]]-=rtrg;
        }
    }
    for(int i=1;i<=m;i++)st[k].push_back(ans[i]+'a');
    //for(int i=1;i<=m;i++)cout<<st[i]<<endl;
    int cp=0;
    for(int i=1;i<=n;i++){
        while(st[i].size()<m){
            while(cnt[cp]==0)cp++;
            st[i].push_back(cp+'a');
            cnt[cp]--;
        }
    }
    sort(st+1,st+1+n);
    for(int i=1;i<=n;i++)cout<<st[i]<<endl;
    return 0;
}