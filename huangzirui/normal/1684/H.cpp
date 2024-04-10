#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,Ln[maxn],Sum[maxn];
string S;
vector<int>ANS;
void getans(int L,int R,int w){
    int k=Sum[R]-Sum[L-1],Lst=L-1;
    // cerr<<"k="<<k<<" w="<<w<<" ["<<L<<","<<R<<"]"<<endl;
    assert(k+k+k>=w+w);
    for(int i=L;i<=R;i++){
        if(S[i-1]!='1'){ANS.push_back(i);continue;}
        if(k==w){
            for(int j=i;j<=R;j++)ANS.push_back(j);
            return;
        }
        // cerr<<"i="<<i<<' '<<k<<' '<<w<<endl;
        ANS.push_back(i+1);
        if(S[i]=='0'){
            if(S[i+1]=='1')ANS.push_back(i+2),i+=2;
            else{
                ANS.push_back(i+2);
                i+=2;
                while(S[i-1]=='0')ANS.push_back(i),++i;
                ANS.push_back(i);
            }
        }else ++i;
        k-=2;w-=3;
        Lst=i;
    }
}
void Solve5(int L,int R){
    for(int i=L;i<=R;i++)
        if(S[i-1]=='1'){
            //11111
            if(S[i]=='1' && S[i+1]=='1' && S[i+2]=='1' && S[i+3]=='1'){
                for(int j=L;j<i;j++)ANS.push_back(j);
                ANS.push_back(i+3);
                for(int j=i+4;j<=R;j++)ANS.push_back(j);
                return;
            }else{
                int chs;
                for(int i=L;i<=R;i++)
                    if(S[i-1]=='1' && S[i]=='0'){chs=i;break;}
                for(int i=L;i<chs;i++)ANS.push_back(i);
                ANS.push_back(chs+2);
                for(int i=chs+3;i<=R;i++)ANS.push_back(i);
                return;
            }
        }
}
void Solve_ex(int L,int R){
    if(Sum[R]-Sum[L-1]==4){
        for(int i=L;;i++)
            if(S[i-1]=='1'){
                if(S[i]=='1'){
                    for(int j=i+2;j<=R;j++)ANS.push_back(j);
                }else{
                    ANS.push_back(i+2);
                    bool B=true;
                    for(int j=i+3;j<=R;j++)
                        if(S[j-1]=='1' && B)B=false;
                        else ANS.push_back(j);
                }
                return;
            }else{
                ANS.push_back(i);
            }
    }else{
        for(int i=L;;i++)
            if(Sum[i]-Sum[L-1]==(Sum[R]-Sum[L-1])/2){
                Solve_ex(L,i);Solve_ex(i+1,R);
                return;
            }
    }
}
void Solve9(int L,int R){
    // cerr<<"solve9 ["<<L<<","<<R<<"]"<<endl;
    for(int i=L;i<=R;i++)
        if(S[i-1]=='0')ANS.push_back(i);
        else{
            if(S[i]=='0' && S[i+1]=='1'){
                ANS.push_back(i+2);
                for(int j=i+3;;j++)
                    if(Sum[j]-Sum[i+2]==4){
                        Solve_ex(i+3,j);
                        for(int k=j+1;k<=R;k++)ANS.push_back(k);
                        return;
                    }
            }else{
                ANS.push_back(i+2);
                getans(i+3,R,16-4-2*(S[i]-'0')-(S[i+1]-'0'));
                return;
            }
        }
}
void Solve10(int L,int R){
    for(int i=L;i<=R;i++)
        if(Sum[i]-Sum[L-1]==4){
            Solve_ex(L,i);
            getans(i+1,R,8);
            return;
        }
}
void solve(int L,int R){
    int k=Sum[R]-Sum[L-1],w=1<<Ln[k-1];
    // cerr<<"solve "<<L<<' '<<R<<' '<<k<<' '<<w<<endl;
    if(k+k+k>=w+w)getans(L,R,w);
    else if(k==5)Solve5(L,R);
    else if(k==9)Solve9(L,R);
    else if(k==10)Solve10(L,R);
    else{
        for(int i=L;i<=R;i++)
            if(Sum[i]-Sum[L-1]>=(k+1)/2){
                solve(L,i);
                if(Ln[k-2]!=Ln[k-1])Solve_ex(i+1,R);
                else solve(i+1,R);
                return;
            }
    }
}
int calc(int L,int R){
    int s=0;
    for(int i=L;i<=R;i++)s=s*2+S[i-1]-'0';
    return s;
}
void check(){
    int num=0;
    int lst=1;
    for(int i=0;i<ANS.size();i++){
        num+=calc(lst,ANS[i]);
        lst=ANS[i]+1;
    }
    // cerr<<"check num="<<num<<endl;
    if(Ln[num]==Ln[num-1]){
        cout<<S<<endl;
        cerr<<"!"<<endl;
        exit(1);
    }
}
int main(){
    Ln[0]=0;
    for(i=1;i<maxn;i++)Ln[i]=Ln[i/2]+1;
    int T;
    cin>>T;
    while(T--){
        k=0;ANS.clear();
        cin>>S;n=S.size();
        for(i=1;i<=n;i++)k+=S[i-1]-'0',Sum[i]=k;
        if(!k){puts("-1");continue;}
        solve(1,S.size());
        ANS.erase(unique(ANS.begin(),ANS.end()),ANS.end());
        printf("%d\n",ANS.size());
        int lst=1;
        for(int i=0;i<ANS.size();i++)printf("%d %d\n",lst,ANS[i]),lst=ANS[i]+1;
        // check();
    }
}