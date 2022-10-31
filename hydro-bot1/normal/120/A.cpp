// Hydro submission #62cd08a2e4874952a0849be2@1657604258957
#include<bits/stdc++.h>
std::string a;
int main(){
	freopen("input.txt","r",stdin);
   	freopen("output.txt","w",stdout);
    int b;
    std::cin >> a >> b;
    if (a == "front") std::cout << ((b == 1) ? 'L' : 'R');
    else if (a == "back") std::cout << ((b == 1) ? 'R' : 'L');
    fclose(stdin);
    fclose(stdout);
    return 0;
}