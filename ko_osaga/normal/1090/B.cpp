#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

char S[101000];

int main()
{
	vector<string> name;
	string now = "";
	map<string, vector<string> > wow;
	bool good = true;
	while (~scanf("%s", S)){
		if (S[0] == '\\'){
			if (S[1] == 'c'){
				for (int i=6;;i++) if (S[i] == '}'){
					S[i] = 0; break;
				}
				name.push_back(S+6);
			}
			else if (S[1] == 'b'){
				if (S[2] == 'e');
				else{
					string ori = S;
					for (int i=9;;i++) if (S[i] == '}'){
						S[i] = 0; break;
					}
					now = S+9;
					if (name[wow.size()] != now) good = false;
					wow[now].push_back(ori);
				}
			}
			else if (S[1] == 'e') break;
		}
		else{
			if (!now.empty()) wow[now].push_back(S);
		}
	}

	if (good) puts("Correct");
	else{
		puts("Incorrect");
		puts("\\begin{thebibliography}{99}");
		for (auto &s : name){
			auto &v = wow[s];
			for (int i=0;i<v.size();i++){
				printf ("%s%c",v[i].c_str(),i+1<v.size()?' ':'\n');
			}
		}
		puts("\\end{thebibliography}");
	}

	return 0;
}