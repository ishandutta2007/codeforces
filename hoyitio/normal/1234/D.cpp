#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxx = 100005;
set<int>  pos[27];
set<int>::iterator it;
char s[maxx];
int main()
{
    scanf("%s",s+1);
    int len = strlen(s+1) , n , x;
    for(int i=1;i<=len;i++){
        int k = s[i]-'a';
        pos[k].insert(i);
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        if(x == 2)
        {
            int l , r ,cnt = 0;
            scanf("%d %d",&l,&r);
            for(int i=0;i<26;i++)
            {
                it = pos[i].lower_bound(l);
                //cout<<*it<<endl;
                if(*it <= r && *it >= l){
                    cnt++;
                }
            }
            cout<<cnt<<endl;
        }
        else{
            int p;
            char c;
            cin>>p>>c;
            getchar();
            int k = c-'a';
            char nowc = s[p];
            s[p] = c;
            pos[nowc-'a'].erase(p);
            pos[c-'a'].insert(p);
        }
    }
    return 0;
}