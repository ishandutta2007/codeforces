#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long llong;

char in[1000001];
int main() {
    vector<string> is;
    map<string, string> rf;
    int idx = 0, cor = 1;
    int mode = 0;
    while (1) {
        gets(in);
        if (mode == 0) {
            if (in[0] == '\\' && in[1] == 'b') {
                mode = 1;
                for (string i : is) {
                    gets(in);
                    string nm = "";
                    for (int j = 9; in[j] != '}'; ++j) nm += in[j];
                    if (i != nm) cor = 0;
                    rf[nm] = in;
                }
                break;
            }
            for (int i = 0; in[i]; ++i) {
                if (in[i] == '\\') {
                    string nm = "";
                    for (int j = i + 6; in[j] != '}'; ++j) {
                        nm += in[j];
                    }
                    is.push_back(nm);
                }
            }
        }
    }
    if (cor) printf("Correct\n");
    else {
        printf("Incorrect\n");
        printf("\\begin{thebibliography}{99}\n");
        for (int i = 0; i < is.size(); ++i) printf("%s\n", rf[is[i]].c_str());
        printf("\\end{thebibliography}\n");
    }
    return 0;
}