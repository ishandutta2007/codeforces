#include <bits/stdc++.h>
using namespace std;
const int mn=1e5+10;
const int sz=300;
const int num=mn/sz+1;
deque<int>d[num];
int cur[num][mn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        d[i/sz].push_back(x);
        cur[i/sz][x]++;
    }
    int q;
    scanf("%d",&q);
    int ans=0;
    while(q--){
        int a,b,c;
        scanf("%d",&a);
        if(a==1){
            scanf("%d%d",&a,&b);
            a=(a+ans-1)%n+1,b=(b+ans-1)%n+1;
            if(a>b)swap(a,b);
            a--,b--;
            int num=d[b/sz][b%sz];
            cur[b/sz][num]--;
            d[b/sz].erase(d[b/sz].begin()+b%sz);
            for(int i=b/sz;i>a/sz;i--){
                cur[i-1][d[i-1].back()]--;
                d[i].push_front(d[i-1].back());
                d[i-1].pop_back();
                cur[i][d[i].front()]++;
            }
            d[a/sz].insert(d[a/sz].begin()+a%sz,num);
            cur[a/sz][num]++;
        }
        else{
            scanf("%d%d%d",&a,&b,&c);
            a=(a+ans-1)%n+1,b=(b+ans-1)%n+1,c=(c+ans-1)%n+1;
            if(a>b)swap(a,b);
            a--,b--;
            ans=0;
            if(a/sz==b/sz){for(int i=a%sz;i<=b%sz;i++)if(d[a/sz][i]==c)ans++;}
            else {
                for (int i = a % sz; i < sz; i++)if (d[a / sz][i] == c)ans++;
                for (int i = a / sz + 1; i < b / sz; i++)ans += cur[i][c];
                for (int i = 0; i <= b % sz; i++)if (d[b / sz][i] == c)ans++;
            }
            printf("%d\n",ans);
        }
    }
}