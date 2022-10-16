#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define SQR(x) (1LL*(x)*(x))
using namespace std;
typedef long long ll;
struct combo {
    char t;
    int pos,len;
    combo() {
        t=pos=len=0;
    }
    combo(char t,int p,int l) {
        this->t=t;
        pos=p;
        len=l;
    }
};
char b[MAX];
combo a[MAX];
int n,m;
void init(void) {
    scanf("%s",b+1);
    m=strlen(b+1);
    a[1]=combo(b[1],1,1);
    n=1;
    FOR(i,2,m) {
        if (b[i]==b[i-1]) a[n].len++;
        else a[++n]=combo(b[i],i,1);
    }
    //FOR(i,1,n) printf("%c %d %d\n",a[i].t,a[i].pos,a[i].len);
}
void count(char t,ll res[]) {
    int s,c[2],del;
    ll sall=0;
    s=c[0]=c[1]=del=0;
    FOR(i,1,n) if (a[i].t==t) {
        ll tmp=1LL*(a[i].len+1)*a[i].len/2;
            if (a[i].len%2==1) {
            res[1]+=SQR((a[i].len+1)/2);
            res[0]+=tmp-SQR((a[i].len+1)/2);
        }
        else {
            res[0]+=SQR(a[i].len/2);
            res[1]+=tmp-SQR(a[i].len/2);
        }
        sall+=1LL*a[i].len*s;
        s+=a[i].len;
        if (a[i].len%2==1) {
            del+=c[a[i].pos%2];
            del-=c[1-a[i].pos%2];
            c[(a[i].pos+a[i].len-1)%2]++;
        }
    }
    res[0]+=(sall-del)/2;
    res[1]+=(sall+del)/2;
}
void process(void) {
    ll res[2];
    res[0]=res[1]=0;
    count('a',res);
    //cout<<res[0]<<" "<<res[1]<<"\n";
    count('b',res);
    cout<<res[0]<<" "<<res[1]<<"\n";
}
int main(void) {
    init();
    process();
    return 0;
}