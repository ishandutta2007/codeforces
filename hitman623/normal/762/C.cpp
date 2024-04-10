#include <bits/stdc++.h>

using namespace std;

int main()
{
    map < char , vector<long> > aa,bb;
    char a[100005],b[100005],d[100005],e[100005],fin[100005];
    long i,n,m,c,j,i1,i2,ma=0,x=-1,y=-1;
    vector <long> a1,b1;
    cin>>a>>b;
    strcpy(d,a);strrev(d);strcpy(e,b);strrev(e);
    m=strlen(a);
    n=strlen(b);
    for(i=0;i<m;++i)
    {
        aa[a[i]].push_back(i+1);
        bb[d[i]].push_back(i+1);
    }
    c=0;
    for(i=0;i<n;++i)
    {
        if(aa[b[i]].size()==0) break;
        c=upper_bound(aa[b[i]].begin(),aa[b[i]].end(),c)-aa[b[i]].begin();
        if(c==aa[b[i]].size()) break;
         c=aa[b[i]][c];
         a1.push_back(c);
    }
    c=0;
    for(i=0;i<n;++i)
    {
        if(bb[e[i]].size()==0) break;
        c=upper_bound(bb[e[i]].begin(),bb[e[i]].end(),c)-bb[e[i]].begin();
        if(c==bb[e[i]].size()) break;
         c=bb[e[i]][c];
         b1.push_back(m-c+1);
    }
    reverse(b1.begin(),b1.end());
    n=a1.size();m=b1.size();c=0;
    if(n==0 && m==0) {cout<<'-';exit(0);}
        x=-1;y=0;c=m;
    for(i=0;i<n;++i)
        if(i+1+m-(upper_bound(b1.begin(),b1.end(),a1[i])-b1.begin())>c)
        {
            c=i+1+m-(upper_bound(b1.begin(),b1.end(),a1[i])-b1.begin());
            x=i;y=upper_bound(b1.begin(),b1.end(),a1[i])-b1.begin();
        }
    j=0;
    for(i=0;i<=x;++i)
    fin[j++]=a[a1[i]-1];
    for(i=y;i<b1.size();++i)
    fin[j++]=a[b1[i]-1];
    fin[j]=0;
    n=strlen(b);
    m=strlen(fin);
    if(n<m) cout<<b;
    else cout<<fin;
    return 0;
}