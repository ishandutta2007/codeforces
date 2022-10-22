#include<iostream>
#include<cstdio>

using namespace std;

int cnt[30];
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 1){
        printf("Yes");
        return 0;
    }
    else{
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(cnt[s[i]-'a'])
            {
                printf("Yes");return 0;
            }
            cnt[s[i]-'a']++;
        }
        printf("No");
    }
    return 0;
}