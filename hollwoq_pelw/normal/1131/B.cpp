#include <bits/stdc++.h>
using namespace std;

int main(){
    long n,a=0,b=0,na,nb;
    cin >> n;
    long ans = 1;
    for (int i = 0; i < n; i++){
        cin >> na >> nb;
        ans += max(0l, min(na,nb)-max(a,b)+1)-(a==b);
        a = na; b = nb;
    }
    cout << ans;
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