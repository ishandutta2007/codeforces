#include <bits/stdc++.h>

typedef long long ll;

using Tiic = std::tuple<int, int, char>;

const int N = 4000;
const int S = 10;

char s1[S], s2[S], s3[S], op;

int n, Cnt = 0;
std::map<std::string, int> Name;
std::map<int, std::string> Base;
std::map<Tiic, int> OPer;
std::map<int, Tiic> Str;

bool Exs(const std::string& name) { return Name.count(name); }
bool Exs(int a, int b, char op) { return OPer.count(Tiic(a, b, op)); }
int CVa(const std::string& name) {
    Name[name] = Cnt;
    Base[Cnt] = name;
    return Cnt++;
}
int COp(const std::string& name, int a, int b, char op) {
    Name[name] = Cnt;
    Base[Cnt] = "";
    Str[Cnt] = Tiic(a, b, op);
    OPer[Tiic(a, b, op)] = Cnt;
    return Cnt++;
}

int nameCount;
std::string makeName() {
    while (true) {
        char name[] = {char(nameCount / (26 * 26 * 26) + 'a'),
                       char(nameCount / (26 * 26) % 26 + 'a'),
                       char(nameCount / 26 % 26 + 'a'),
                       char(nameCount % 26 + 'a'), 0};
        ++nameCount;
        if (Exs(name)) continue;
        return name;
    }
}

int main() {
    std::scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char e;
        std::scanf(" %[^=]%c%[^$^#&\n]%c", s1, &e, s2, &op);
        if (op == '\n') {
            if (!Exs(s2)) CVa(s2);
            Name[s1] = Name[s2];
        } else {
            std::scanf("%s", s3);
            if (!Exs(s2)) CVa(s2);
            if (!Exs(s3)) CVa(s3);
            int a = Name[s2], b = Name[s3];
            if (!Exs(a, b, op)) {
                COp(s1, a, b, op);
            } else {
                Name[s1] = OPer[Tiic(a, b, op)];
            }
        }
    }
    if (Exs("res")) {
        int res = Name["res"];
        if (Base[res].length()) {
            if (Base[res] == "res")
                std::puts("0");
            else {
                std::puts("1");
                std::printf("res=%s\n", Base[res].data());
            }

        } else {
            std::set<int> Use;
            std::map<int, std::string> OMap;
            std::queue<int> q;
            Use.insert(res);
            q.push(res);
            do {
                int p = q.front();
                q.pop();
                auto& Sou = Str[p];
                int a = std::get<0>(Sou), b = std::get<1>(Sou);
                if (!Use.count(a)) {
                    if (Base[a].length()) {
                        OMap[a] = Base[a];
                    } else {
                        Use.insert(a), q.push(a);
                    }
                }
                if (!Use.count(b)) {
                    if (Base[b].length()) {
                        OMap[b] = Base[b];
                    } else {
                        Use.insert(b), q.push(b);
                    }
                }

            } while (!q.empty());
            std::vector<std::string> Res;
            for (int p : Use) {
                if (OMap.count(p)) continue;
                OMap[p] = p == res ? "res" : makeName();
                auto& Sou = Str[p];
                int a = std::get<0>(Sou), b = std::get<1>(Sou);
                char op = std::get<2>(Sou);
                Res.push_back(OMap[p] + '=' + OMap[a] + op + OMap[b]);
            }
            std::printf("%d\n", int(Res.size()));
            for (auto&& s : Res) std::puts(s.data());
        }
    } else {
        std::puts("0");
    }
    return 0;
}