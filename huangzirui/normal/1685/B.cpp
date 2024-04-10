#include<bits/stdc++.h>
using namespace std;
const int maxn=800010;
int i,j,k,n,m,A,B,C,D;
int w[2][maxn];int cnt[2];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cnt[0]=cnt[1]=0;
        scanf("%d%d%d%d",&A,&B,&C,&D);
        cin>>S;
        int w1=0;for(i=0;i<S.size();i++)w1+=S[i]=='A';
        if(w1!=A+C+D){puts("NO");continue;}
        int lst=1,num=0;
        for(i=2;i<=S.size()+1;i++)
            if(i>S.size() || S[i-2]==S[i-1]){
                num+=(i-lst-1)/2;
                if((i-lst)&1);
                else{
                    int id=S[i-2]=='A';
                    w[id][++cnt[id]]=(i-lst)/2;
                }
                lst=i;
            }
        // cerr<<num<<' '<<cnt[0]<<' '<<cnt[1]<<endl;
        sort(w[0]+1,w[0]+1+cnt[0]);
        sort(w[1]+1,w[1]+1+cnt[1]);
        int c1=C,c2=D;
        for(i=1;i<=cnt[0];i++)
            if(c1>=w[0][i])c1-=w[0][i],++num;
            else break;
        for(i=1;i<=cnt[1];i++)
            if(c2>=w[1][i])c2-=w[1][i],++num;
            else break;
        if(num>=C+D){puts("YES");}
        else puts("NO");
    }
}