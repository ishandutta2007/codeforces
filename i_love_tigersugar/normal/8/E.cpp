#include<bits/stdc++.h>
typedef long long ll;
int n;
ll k;
ll f[33][3][3];
int bv(const int &x,const int &i) {
    return ((x|(1<<(i-n/2)))==x);
}
void init(void) {
    scanf("%d",&n);
    scanf("%I64d",&k);
    k++;
}
ll optimize(const int &pre) {
    //printf("Counting prefix %d\n",pre);
    int lp,i,j,k,l;
    if (pre>0) {
        lp=0;
        while (bv(pre,n-1-lp)==bv(pre-1,n-1-lp)) lp++;
    }
    else {
        lp=1;
        memset(f,0,sizeof f);
        for (i=0;i<2;i=i+1)
            f[0][i>bv(pre,n-1)][1-i>bv(pre,n-1)]++;
    }   
    //printf("First different point: %d\n",lp);
    for (i=lp;i<=n/2;i=i+1) 
        for (j=0;j<2;j=j+1)
            for (k=0;k<2;k=k+1)
                f[i][j][k]=0LL;
    for (i=lp-1;i<n/2-1;i=i+1)
        for (j=0;j<2;j=j+1)
            for (k=0;k<2;k=k+1)
                for (l=0;l<2;l=l+1)
                    if ((j||(l>=bv(pre,n-i-2))) && (k||(1-l>=bv(pre,n-i-2))))
                        f[i+1][j||(l>bv(pre,n-i-2))][k||(1-l>bv(pre,n-i-2))]+=f[i][j][k];
    /*for (i=0;i<n/2;i=i+1)
        for (j=0;j<2;j=j+1)
            for (k=0;k<2;k=k+1)
                if (f[i][j][k]>0) printf("f(%d,%d,%d)=%I64d\n",i,j,k,f[i][j][k]);*/
    int u,v;
    u=0;
    if ((n%2==1) && (pre%2==1)) v=1; else v=0;
    ll ret=0LL;
    for (j=1;j>=u;j=j-1)
        for (k=1;k>=v;k=k-1)
            ret=ret+f[n/2-1][j][k];
    //printf("Count of prefix %d is %I64d\n",pre,ret);
    return (ret);
}
void trace(void) {
    int i,j,u,v,pre;
    int m1,m2,t1,t2,g;
    bool found=false;
    ll s;
    for (pre=0;pre<(1<<(n-n/2-1));pre++) {
        s=optimize(pre);
        if (s>=k) {
            //printf("Prefix found: %d\n",pre);
            found=true;
            break;
        };
        k=k-s;
    }
    if (!found) {
        printf("-1");
        return;
    }
    for (i=n-1;i>=n/2;i=i-1) printf("%d",bv(pre,i)); //printf("\n");
    m1=0;
    m2=0;   
    if ((n%2==1) && (pre%2==1)) g=true; else g=false;
    for (i=n/2-1;i>=1;i=i-1)
        for (j=0;j<2;j=j+1) {
            s=0LL;
            if (j>bv(pre,n-i-1)) t1=1;
            else if (j<bv(pre,n-i-1)) t1=-1;
            else t1=m1;
            if (1-j>bv(pre,n-i-1)) t2=1;
            else if (1-j<bv(pre,n-i-1)) t2=-1;
            else t2=m2;
            //printf("%d %d\n",t1,t2);
            for (u=1;u>=(t1<0);u=u-1)
                for (v=1;v>=((t2<0) || ((t2==0) && g));v=v-1)
                    s=s+f[i-1][u][v];
            //printf("i= %d, j = %d, s = %I64d, k = %I64d\n",i,j,s,k);
            if (s>=k) {             
                //printf("Choose i = %d is %d\n",i,j);
                printf("%d",j);
                m1=t1;
                m2=t2;
                break;
            }
            k=k-s;
        }
    if (k>1) printf("1");
    else {
        if ((t2<0) || ((t2==0) && g)) printf("0");
        else if (m1<0) printf("1");
        else printf("0");
    }
}
int main(void) {
    init();
    trace();
    return 0;
}