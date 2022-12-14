#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e6;
int N;
int one[4], two[4], three;

int main(){
    for(int i=0;i<4;++i) one[i] = two[i] = INF;
    three = INF;
    scanf("%d", &N);
    while(N--){
        int num; char s[5];
        scanf("%d %s", &num, s);
        if(strlen(s)==1) one[s[0]-'A'] = min(one[s[0]-'A'], num);
        else if(strlen(s)==2){
            if(s[0]!='C'&&s[1]!='C') two[0] = min(two[0], num), one[0] = min(one[0], num), one[1] = min(one[1], num);
            if(s[0]!='A'&&s[1]!='A') two[1] = min(two[1], num), one[2] = min(one[2], num), one[1] = min(one[1], num);
            if(s[0]!='B'&&s[1]!='B') two[2] = min(two[2], num), one[0] = min(one[0], num), one[2] = min(one[2], num);
        }
        else{
            three = min(three, num);
            two[0] = min(two[0], num), one[0] = min(one[0], num), one[1] = min(one[1], num);
            two[1] = min(two[1], num), one[2] = min(one[2], num), one[1] = min(one[1], num);
            two[2] = min(two[2], num), one[0] = min(one[0], num), one[2] = min(one[2], num);
        }
    }
    if(three>=INF&&one[0]+two[1]>=INF&&one[1]+two[2]>=INF&&one[2]+two[0]>=INF&&one[0]+one[1]+one[2]>=INF) puts("-1");
    else printf("%d", min(three, min(one[0]+two[1], min(one[1]+two[2], min(one[2]+two[0], one[0]+one[1]+one[2])))));
    return 0;
}