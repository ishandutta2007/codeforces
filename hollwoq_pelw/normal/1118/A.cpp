#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    while(q--){
        long long n,a,b;
        cin >> n >> a >> b;
        if (b < 2*a) cout << b*(n/2)+a*(n%2);
        else cout << n*a;
        cout << "\n";
    }
    return 0;
    
}
/*
{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}{{}}









(())(())(())(())(())(())(())(())(())(())(())(())(())(())(())(())(())

 \||/     \||/    \?+==-=-==      |+==|       |+==|       \\=   =//
  |/ |!|!| \|      ?|/       |    ||          ||          |\\+=+//|
  ||   +   ||   |  |/   |    ++=  || )&^@!    || $@^(~    / \\=// \
  +|==???==|+  =+  |++==+=-|      |+   %      |+   *     |  =+X+=  |
  ||   +   ||   |  |\   |    ++=  || ]&"*~    || %'&}!    \ //=\\ /
  |\ |!|!| /|      ?|\       |    ||          ||          |//+=+\\|
 /||\     /||\    /?+==-=-==      |+==+==+=|  |+==+==+=|  //=   =\\

>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<









[[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]][[]]
*/