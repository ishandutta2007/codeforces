#include <bits/stdc++.h>
using namespace std;
int N; char s[1004];
set < int > st;
int main(){
    scanf("%d", &N);
    while(N--){
        scanf("%s", s);
        int num = 0;
        for(int i=0;i<strlen(s);i++) num = num|(1<<(s[i]-'a'));
        st.insert(num);
    }
    printf("%d", st.size());
    return 0;
}