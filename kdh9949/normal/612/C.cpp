#include <cstdio>
#include <stack>
using namespace std;

char str[1000010];
stack<char> st;
int ans;

int main(){
    scanf("%s", str);
    for(int i = 0; str[i]; i++){
        if(str[i] == '<' || str[i] == '(' || str[i] == '{' || str[i] == '[') st.push(str[i]);
        else{
            if(st.empty()){ puts("Impossible"); return 0;}
            if(!(st.top() == '(' && str[i] == ')' ||
                 st.top() == '{' && str[i] == '}' ||
                 st.top() == '[' && str[i] == ']' ||
                 st.top() == '<' && str[i] == '>' )) ans++;
            st.pop();
        }
    }
    if(!st.empty()) puts("Impossible");
    else printf("%d", ans);
}