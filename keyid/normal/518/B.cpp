#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXL=200005;

char s[MAXL],t[MAXL];
int cnt[200],cnt2[200];

int main()
{
    scanf("%s%s",s,t);
    int l1=strlen(s),l2=strlen(t);
    for (int i=0;i<l2;i++) cnt[t[i]]++;
    int ans1=0,ans2=0;
    for (int i=0;i<l1;i++)
        if (cnt[s[i]])
        {
            ans1++;
            cnt[s[i]]--;
        }
        else cnt2[s[i]]++;
    for (char i='a';i<='z';i++) ans2+=min(cnt2[i],cnt[i-32]);
    for (char i='A';i<='Z';i++) ans2+=min(cnt2[i],cnt[i+32]);
    printf("%d %d",ans1,ans2);
    return 0;
}