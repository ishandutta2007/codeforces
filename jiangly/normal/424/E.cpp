#include<bits/stdc++.h>
using namespace std;
using LL=long long;
class Solver{
private:
    static constexpr int INF=1e9;
    unordered_map<LL,double> dp;
    class State{
    public:
        int n;
        char a[10];
        State():n(0),a{}{}
        void Canonize(){
            static char c[3];
            int real_n=0;
            for(int i=0;i<n;++i){
                c[0]=a[i]&3;
                c[1]=(a[i]>>2)&3;
                c[2]=a[i]>>4;
                if(i!=n-1&&(c[1]==0||c[0]==0&&c[2]==0)){
                    continue;
                }
                if(i!=n-1&&(c[0]==0||c[2]==0)){
                    c[1]=1;
                }
                if(c[0]>c[2]){
                    swap(c[0],c[2]);
                }
                a[real_n++]=c[0]|(c[1]<<2)|(c[2]<<4);
            }
            for(int i=real_n;i<n;++i){
                a[i]=0;
            }
            n=real_n;
            sort(a,a+n-1);
        }
        LL toLL()const{
            LL x=0;
            for(int i=0;i<n;++i){
                x|=(LL)a[i]<<(i*6);
            }
            return x;
        }
        char getColor(int x,int y)const{
            return (a[x]>>(y*2))&3;
        }
    };
    double dfsDP(State a){
        a.Canonize();
        LL x=a.toLL();
        if(dp.count(x)){
            return dp[x];
        }
        bool color_able[4]={};
        for(int i=0;i<a.n-1;++i){
            if(a.getColor(i,0)>0&&a.getColor(i,2)>0){
                color_able[a.getColor(i,1)]=true;
            }
            if(a.getColor(i,1)>0){
                color_able[a.getColor(i,0)]=true;
                color_able[a.getColor(i,2)]=true;
            }
        }
        if(!color_able[1]&&!color_able[2]&&!color_able[3]){
            return dp[x]=0;
        }
        double mn[4]={INF,INF,INF,INF};
        int next=a.n-1;
        bool able[3];
        for(int i=0;i<3;++i){
            able[i]=(a.getColor(next,i)==0);
        }
        if(!able[0]&&!able[1]&&!able[2]){
            next=a.n;
            for(int i=0;i<3;++i){
                able[i]=(a.getColor(next,i)==0);
            }
        }
        double p[4]={};
        double sum_p=0;
        if(color_able[1]){
            p[1]=1.0/6;
            sum_p+=1.0/6;
        }
        if(color_able[2]){
            p[2]=1.0/3;
            sum_p+=1.0/3;
        }
        if(color_able[3]){
            p[3]=1.0/3;
            sum_p+=1.0/3;
        }
        char c[3];
        for(int i=0;i<a.n-1;++i){
            for(int j=0;j<3;++j){
                c[j]=a.getColor(i,j);
            }
            if(c[0]>0&&c[1]>0&&c[2]>0&&mn[c[1]]>0){
                State b=a;
                b.n=next+1;
                b.a[i]&=~12;
                for(int j=0;j<3;++j){
                    if(able[j]){
                        b.a[next]|=c[1]<<(j*2);
                        mn[c[1]]=min(mn[c[1]],dfsDP(b));
                        b.a[next]&=~(3<<(j*2));
                    }
                }
            }
            if(c[0]>0&&c[1]>0&&mn[c[0]]>0){
                State b=a;
                b.n=next+1;
                b.a[i]&=~3;
                for(int j=0;j<3;++j){
                    if(able[j]){
                        b.a[next]|=c[0]<<(j*2);
                        mn[c[0]]=min(mn[c[0]],dfsDP(b));
                        b.a[next]&=~(3<<(j*2));
                    }
                }
            }
            if(c[1]>0&&c[2]>0&&mn[c[2]]>0){
                State b=a;
                b.n=next+1;
                b.a[i]&=~48;
                for(int j=0;j<3;++j){
                    if(able[j]){
                        b.a[next]|=c[2]<<(j*2);
                        mn[c[2]]=min(mn[c[2]],dfsDP(b));
                        b.a[next]&=~(3<<(j*2));
                    }
                }
            }
        }
        double ans=0;
        for(int i=1;i<=3;++i){
            ans+=p[i]*mn[i];
        }
        return dp[x]=(ans+1)/sum_p;
    }
public:
    Solver(){}
    void solve(){
        int n;
        cin>>n;
        State f;
        f.n=n;
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            for(int j=0;j<3;++j){
                switch(s[j]){
                    case 'R':
                        f.a[i]|=1<<(j*2);
                        break;
                    case 'G':
                        f.a[i]|=2<<(j*2);
                        break;
                    case 'B':
                        f.a[i]|=3<<(j*2);
                        break;
                }
            }
        }
        printf("%.10lf\n",dfsDP(f));
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Solver().solve();
    return 0;
}