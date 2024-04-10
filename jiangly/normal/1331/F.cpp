#include <iostream>
#include <vector>
#include <set>
#include <functional>
std::set<std::string> e{"H", "HE", "LI", "BE", "B", "C", "N", "O", "F", "NE", "NA", "MG", "AL", "SI", "P", "S", "CL", "AR", "K", "CA", "SC", "TI", "V", "CR", "MN", "FE", "CO", "NI", "CU", "ZN", "GA", "GE", "AS", "SE", "BR", "KR", "RB", "SR", "Y", "ZR", "NB", "MO", "TC", "RU", "RH", "PD", "AG", "CD", "IN", "SN", "SB", "TE", "I", "XE", "CS", "BA", "HF", "TA", "W", "RE", "OS", "IR", "PT", "AU", "HG", "TL", "PB", "BI", "PO", "AT", "RN", "FR", "RA", "RF", "DB", "SG", "BH", "HS", "MT", "DS", "RG", "CN", "NH", "FL", "MC", "LV", "TS", "OG", "LA", "CE", "PR", "ND", "PM", "SM", "EU", "GD", "TB", "DY", "HO", "ER", "TM", "YB", "LU", "AC", "TH", "PA", "U", "NP", "PU", "AM", "CM", "BK", "CF", "ES", "FM", "MD", "NO", "LR"};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    std::vector<int> dp(s.length() + 1);
    dp[0] = 1;
    for (int i = 1; i <= s.length(); ++i)
        for (int j = 1; j <= 2 && j <= i; ++j)
            dp[i] |= dp[i - j] & e.count(s.substr(i - j, j));
    std::cout << (dp.back() ? "YES" : "NO") << "\n";
    return 0;
}