#include<bits/stdc++.h>
using namespace std;
int n, q, cnt;
set<int> lft;
vector<int> eve[300005];

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++) {
        int A, B;
        scanf("%d%d",&A,&B);
        if(A == 1) {
            cnt++;
            eve[B].push_back(cnt);
            lft.insert(cnt);
        }
        if(A == 2) {
            while(eve[B].size()>0) {
                int cur = eve[B].back(); eve[B].pop_back();
                if(lft.find(cur) != lft.end()) lft.erase(cur);
            }
        }
        if(A == 3) {
            while(lft.size()>0) {
                set<int>::iterator it = lft.begin();
                if(*it>B) break;
                lft.erase(it);
            }
        }
        printf("%d\n",lft.size());
    }
}