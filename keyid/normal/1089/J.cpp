#include <bits/stdc++.h>
using namespace std;

int n, m;
string reserved[50];
unordered_set<string> is_reserved;
string buf;

vector<string> tokens;

unordered_map<string, string> trans;

void dfs(int len, string now){
	if(len == now.length()){
		if(is_reserved.find(now) != is_reserved.end())return;
		tokens.push_back(now);
		return;
	}
    for(int i = 0 ; i < 26 ; i++){
		string tmp = now;
        tmp += char(i + 'a');
        dfs(len, tmp);
	}
}

void gen_tokens(){
    for(int l = 1 ; l <= 3 ; l++)
        dfs(l, "");
}

bool num_char(char a){
    return a >= '0' && a <= '9';
}
bool word_char(char a){
    if(a == '_' || a == '$')return true;
    if(a >= 'a' && a <= 'z')return true;
    if(a >= 'A' && a <= 'Z')return true;
    if(a >= '0' && a <= '9')return true;
    return false;
}

bool check_reserved(const string& txt){
    return is_reserved.find(txt) != is_reserved.end();
}
bool check_num(const string& txt){
    for(int i = 0 ; i < txt.length() ; i++)
		if(!num_char(txt[i]))
			return false;
	return true;
}
bool check_word(const string& txt){
    if(txt[0] >= '0' && txt[0] <= '9')
		return false;
	for(int i = 0 ; i < txt.length() ; i++)
        if(!word_char(txt[i]))return false;
    return true;
}

string ans;
string last_token, last_unparsed;
vector<int> st;
/*
bool last_reserved;
bool last_num;
bool last_word;*/

void Add(const string& a, bool is_reserved, bool is_num, bool is_word){

	//cout << "a = " << a << endl;

    bool need_add_extra_space = false;

    if(!last_unparsed.empty()){
		string tmp = last_token + a[0];

		if(check_num(tmp))
			need_add_extra_space = true;
		if(check_word(tmp))
			need_add_extra_space = true;

		//if(need_add_extra_space)cout << "because of word or num" <<endl;
    }

    if(!need_add_extra_space){
		string tmp2 = last_unparsed + a;

        int index = 0, nxt_st;

		for(int start : st){
			index++;
            if(index < st.size())nxt_st = st[index];
            else nxt_st = last_unparsed.length();

            for(int i = 1 ; i <= n ; i++){
                if(start + reserved[i].length() > tmp2.length())continue;
                if(tmp2.substr(start, reserved[i].length()) == reserved[i]
                && reserved[i].length() > nxt_st - start){
                    need_add_extra_space = true;
                }
            }
		}

		//if(need_add_extra_space)cout << "because of reserved" <<endl;
	}

    if(need_add_extra_space)ans += ' ';
    ans += a;

    last_token = a;
    if(need_add_extra_space){
		last_unparsed = a;
        st.clear();
        st.push_back(0);
	}
    else{
        st.push_back(last_unparsed.length());
		last_unparsed += a;
    }
}

int main(){
#ifdef local
	freopen("read.txt", "r",stdin);
#endif

	cin >> n;
    for(int i = 1 ; i <= n ; i++){
		cin >> reserved[i];
		is_reserved.insert(reserved[i]);
	}

	gen_tokens();

    cin >> m;scanf(" ");
    for(int _ = 1 ; _ <= m ; _++){
		//buf = cin.getline(10000);
        getline(cin, buf);
        string pre;

        //cout << ": " << buf << ":" <<endl;

        for(int i = 0 ; i < buf.length() ; i++){
            if(buf[i] == '#')break;
            if(buf[i] == ' ')continue;

            int longest = -1;

            for(int ed = buf.length() ; ed > i ; ed--){
                string txt = buf.substr(i, ed - i);

                //cout << "i = " << i <<", " << txt << endl;

                bool f1 = check_reserved(txt);
                bool f2 = check_num(txt);
                bool f3 = check_word(txt);

                if(!f1 && !f2 && !f3)continue;

                longest = ed;

                if(f1){
                    Add(txt, true, false, false);
                }
                else{
                    if(f2){
                        Add(txt, false, true, false);
                    }
                    else{ // f3
                        if(trans.find(txt) == trans.end()){
                            int now_size = trans.size();
                            trans[txt] = tokens[now_size];
                        }
                        Add(trans[txt], false, false ,true);
                    }
                }

                break;
            }

            assert(longest != -1);
            i = longest - 1;
        }
    }

    cout << ans << endl;
    return 0;
}