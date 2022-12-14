#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = (1<<8);
int n;
string dp[500];

int tobin (string s) {
    int res=0;
    for (int i=0; i<s.size(); i++) {
        res=res*2+(s[i]=='1');
    }
    return res;
}

void precompute () {
    dp[tobin("00000000")]="!x&x";
    dp[tobin("00000001")]="x&y&z";
    dp[tobin("00000010")]="!z&x&y";
    dp[tobin("00000011")]="x&y";
    dp[tobin("00000100")]="!y&x&z";
    dp[tobin("00000101")]="x&z";
    dp[tobin("00000110")]="!y&x&z|!z&x&y";
    dp[tobin("00000111")]="(y|z)&x";
    dp[tobin("00001000")]="!y&!z&x";
    dp[tobin("00001001")]="!y&!z&x|x&y&z";
    dp[tobin("00001010")]="!z&x";
    dp[tobin("00001011")]="!z&x|x&y";
    dp[tobin("00001100")]="!y&x";
    dp[tobin("00001101")]="!y&x|x&z";
    dp[tobin("00001110")]="!(y&z)&x";
    dp[tobin("00001111")]="x";
    dp[tobin("00010000")]="!x&y&z";
    dp[tobin("00010001")]="y&z";
    dp[tobin("00010010")]="!x&y&z|!z&x&y";
    dp[tobin("00010011")]="(x|z)&y";
    dp[tobin("00010100")]="!x&y&z|!y&x&z";
    dp[tobin("00010101")]="(x|y)&z";
    dp[tobin("00010110")]="!x&y&z|!y&x&z|!z&x&y";
    dp[tobin("00010111")]="(x|y)&z|x&y";
    dp[tobin("00011000")]="!x&y&z|!y&!z&x";
    dp[tobin("00011001")]="!y&!z&x|y&z";
    dp[tobin("00011010")]="!x&y&z|!z&x";
    dp[tobin("00011011")]="!z&x|y&z";
    dp[tobin("00011100")]="!x&y&z|!y&x";
    dp[tobin("00011101")]="!y&x|y&z";
    dp[tobin("00011110")]="!(y&z)&x|!x&y&z";
    dp[tobin("00011111")]="x|y&z";
    dp[tobin("00100000")]="!x&!z&y";
    dp[tobin("00100001")]="!x&!z&y|x&y&z";
    dp[tobin("00100010")]="!z&y";
    dp[tobin("00100011")]="!z&y|x&y";
    dp[tobin("00100100")]="!x&!z&y|!y&x&z";
    dp[tobin("00100101")]="!x&!z&y|x&z";
    dp[tobin("00100110")]="!y&x&z|!z&y";
    dp[tobin("00100111")]="!z&y|x&z";
    dp[tobin("00101000")]="!(!x&!y|x&y|z)";
    dp[tobin("00101001")]="!(!x&!y|x&y|z)|x&y&z";
    dp[tobin("00101010")]="!z&(x|y)";
    dp[tobin("00101011")]="!z&(x|y)|x&y";
    dp[tobin("00101100")]="!x&!z&y|!y&x";
    dp[tobin("00101101")]="!x&!z&y|!y&x|x&z";
    dp[tobin("00101110")]="!y&x|!z&y";
    dp[tobin("00101111")]="!z&y|x";
    dp[tobin("00110000")]="!x&y";
    dp[tobin("00110001")]="!x&y|y&z";
    dp[tobin("00110010")]="!(x&z)&y";
    dp[tobin("00110011")]="y";
    dp[tobin("00110100")]="!x&y|!y&x&z";
    dp[tobin("00110101")]="!x&y|x&z";
    dp[tobin("00110110")]="!(x&z)&y|!y&x&z";
    dp[tobin("00110111")]="x&z|y";
    dp[tobin("00111000")]="!x&y|!y&!z&x";
    dp[tobin("00111001")]="!x&y|!y&!z&x|y&z";
    dp[tobin("00111010")]="!x&y|!z&x";
    dp[tobin("00111011")]="!z&x|y";
    dp[tobin("00111100")]="!x&y|!y&x";
    dp[tobin("00111101")]="!x&y|!y&x|x&z";
    dp[tobin("00111110")]="!(x&z)&y|!y&x";
    dp[tobin("00111111")]="x|y";
    dp[tobin("01000000")]="!x&!y&z";
    dp[tobin("01000001")]="!x&!y&z|x&y&z";
    dp[tobin("01000010")]="!x&!y&z|!z&x&y";
    dp[tobin("01000011")]="!x&!y&z|x&y";
    dp[tobin("01000100")]="!y&z";
    dp[tobin("01000101")]="!y&z|x&z";
    dp[tobin("01000110")]="!y&z|!z&x&y";
    dp[tobin("01000111")]="!y&z|x&y";
    dp[tobin("01001000")]="!(!x&!z|x&z|y)";
    dp[tobin("01001001")]="!(!x&!z|x&z|y)|x&y&z";
    dp[tobin("01001010")]="!x&!y&z|!z&x";
    dp[tobin("01001011")]="!x&!y&z|!z&x|x&y";
    dp[tobin("01001100")]="!y&(x|z)";
    dp[tobin("01001101")]="!y&(x|z)|x&z";
    dp[tobin("01001110")]="!y&z|!z&x";
    dp[tobin("01001111")]="!y&z|x";
    dp[tobin("01010000")]="!x&z";
    dp[tobin("01010001")]="!x&z|y&z";
    dp[tobin("01010010")]="!x&z|!z&x&y";
    dp[tobin("01010011")]="!x&z|x&y";
    dp[tobin("01010100")]="!(x&y)&z";
    dp[tobin("01010101")]="z";
    dp[tobin("01010110")]="!(x&y)&z|!z&x&y";
    dp[tobin("01010111")]="x&y|z";
    dp[tobin("01011000")]="!x&z|!y&!z&x";
    dp[tobin("01011001")]="!x&z|!y&!z&x|y&z";
    dp[tobin("01011010")]="!x&z|!z&x";
    dp[tobin("01011011")]="!x&z|!z&x|x&y";
    dp[tobin("01011100")]="!x&z|!y&x";
    dp[tobin("01011101")]="!y&x|z";
    dp[tobin("01011110")]="!(x&y)&z|!z&x";
    dp[tobin("01011111")]="x|z";
    dp[tobin("01100000")]="!(!y&!z|x|y&z)";
    dp[tobin("01100001")]="!(!y&!z|x|y&z)|x&y&z";
    dp[tobin("01100010")]="!x&!y&z|!z&y";
    dp[tobin("01100011")]="!x&!y&z|!z&y|x&y";
    dp[tobin("01100100")]="!x&!z&y|!y&z";
    dp[tobin("01100101")]="!x&!z&y|!y&z|x&z";
    dp[tobin("01100110")]="!y&z|!z&y";
    dp[tobin("01100111")]="!y&z|!z&y|x&y";
    dp[tobin("01101000")]="!(!x&!y|x&y|z)|!x&!y&z";
    dp[tobin("01101001")]="!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
    dp[tobin("01101010")]="!x&!y&z|!z&(x|y)";
    dp[tobin("01101011")]="!x&!y&z|!z&(x|y)|x&y";
    dp[tobin("01101100")]="!x&!z&y|!y&(x|z)";
    dp[tobin("01101101")]="!x&!z&y|!y&(x|z)|x&z";
    dp[tobin("01101110")]="!y&(x|z)|!z&y";
    dp[tobin("01101111")]="!y&z|!z&y|x";
    dp[tobin("01110000")]="!x&(y|z)";
    dp[tobin("01110001")]="!x&(y|z)|y&z";
    dp[tobin("01110010")]="!x&z|!z&y";
    dp[tobin("01110011")]="!x&z|y";
    dp[tobin("01110100")]="!x&y|!y&z";
    dp[tobin("01110101")]="!x&y|z";
    dp[tobin("01110110")]="!(x&y)&z|!z&y";
    dp[tobin("01110111")]="y|z";
    dp[tobin("01111000")]="!x&(y|z)|!y&!z&x";
    dp[tobin("01111001")]="!x&(y|z)|!y&!z&x|y&z";
    dp[tobin("01111010")]="!x&(y|z)|!z&x";
    dp[tobin("01111011")]="!x&z|!z&x|y";
    dp[tobin("01111100")]="!x&(y|z)|!y&x";
    dp[tobin("01111101")]="!x&y|!y&x|z";
    dp[tobin("01111110")]="!x&y|!y&z|!z&x";
    dp[tobin("01111111")]="x|y|z";
    dp[tobin("10000000")]="!(x|y|z)";
    dp[tobin("10000001")]="!(x|y|z)|x&y&z";
    dp[tobin("10000010")]="!(!x&y|!y&x|z)";
    dp[tobin("10000011")]="!(x|y|z)|x&y";
    dp[tobin("10000100")]="!(!x&z|!z&x|y)";
    dp[tobin("10000101")]="!(x|y|z)|x&z";
    dp[tobin("10000110")]="!(!x&y|!y&x|z)|!y&x&z";
    dp[tobin("10000111")]="!(x|y|z)|(y|z)&x";
    dp[tobin("10001000")]="!y&!z";
    dp[tobin("10001001")]="!y&!z|x&y&z";
    dp[tobin("10001010")]="!(!x&y|z)";
    dp[tobin("10001011")]="!y&!z|x&y";
    dp[tobin("10001100")]="!(!x&z|y)";
    dp[tobin("10001101")]="!y&!z|x&z";
    dp[tobin("10001110")]="!(!x&y|z)|!y&x";
    dp[tobin("10001111")]="!y&!z|x";
    dp[tobin("10010000")]="!(!y&z|!z&y|x)";
    dp[tobin("10010001")]="!(x|y|z)|y&z";
    dp[tobin("10010010")]="!(!x&y|!y&x|z)|!x&y&z";
    dp[tobin("10010011")]="!(x|y|z)|(x|z)&y";
    dp[tobin("10010100")]="!(!x&z|!z&x|y)|!x&y&z";
    dp[tobin("10010101")]="!(x|y|z)|(x|y)&z";
    dp[tobin("10010110")]="!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
    dp[tobin("10010111")]="!(x|y|z)|(x|y)&z|x&y";
    dp[tobin("10011000")]="!x&y&z|!y&!z";
    dp[tobin("10011001")]="!y&!z|y&z";
    dp[tobin("10011010")]="!(!x&y|z)|!x&y&z";
    dp[tobin("10011011")]="!(!x&y|z)|y&z";
    dp[tobin("10011100")]="!(!x&z|y)|!x&y&z";
    dp[tobin("10011101")]="!(!x&z|y)|y&z";
    dp[tobin("10011110")]="!(!x&y|z)|!x&y&z|!y&x";
    dp[tobin("10011111")]="!y&!z|x|y&z";
    dp[tobin("10100000")]="!x&!z";
    dp[tobin("10100001")]="!x&!z|x&y&z";
    dp[tobin("10100010")]="!(!y&x|z)";
    dp[tobin("10100011")]="!x&!z|x&y";
    dp[tobin("10100100")]="!x&!z|!y&x&z";
    dp[tobin("10100101")]="!x&!z|x&z";
    dp[tobin("10100110")]="!(!y&x|z)|!y&x&z";
    dp[tobin("10100111")]="!(!y&x|z)|x&z";
    dp[tobin("10101000")]="!(x&y|z)";
    dp[tobin("10101001")]="!(x&y|z)|x&y&z";
    dp[tobin("10101010")]="!z";
    dp[tobin("10101011")]="!z|x&y";
    dp[tobin("10101100")]="!x&!z|!y&x";
    dp[tobin("10101101")]="!(x&y|z)|x&z";
    dp[tobin("10101110")]="!y&x|!z";
    dp[tobin("10101111")]="!z|x";
    dp[tobin("10110000")]="!(!y&z|x)";
    dp[tobin("10110001")]="!x&!z|y&z";
    dp[tobin("10110010")]="!(!y&x|z)|!x&y";
    dp[tobin("10110011")]="!x&!z|y";
    dp[tobin("10110100")]="!(!y&z|x)|!y&x&z";
    dp[tobin("10110101")]="!(!y&z|x)|x&z";
    dp[tobin("10110110")]="!(!y&x|z)|!x&y|!y&x&z";
    dp[tobin("10110111")]="!x&!z|x&z|y";
    dp[tobin("10111000")]="!x&y|!y&!z";
    dp[tobin("10111001")]="!(x&y|z)|y&z";
    dp[tobin("10111010")]="!x&y|!z";
    dp[tobin("10111011")]="!z|y";
    dp[tobin("10111100")]="!(!x&!y&z|x&y)";
    dp[tobin("10111101")]="!x&!z|!y&x|y&z";
    dp[tobin("10111110")]="!x&y|!y&x|!z";
    dp[tobin("10111111")]="!z|x|y";
    dp[tobin("11000000")]="!x&!y";
    dp[tobin("11000001")]="!x&!y|x&y&z";
    dp[tobin("11000010")]="!x&!y|!z&x&y";
    dp[tobin("11000011")]="!x&!y|x&y";
    dp[tobin("11000100")]="!(!z&x|y)";
    dp[tobin("11000101")]="!x&!y|x&z";
    dp[tobin("11000110")]="!(!z&x|y)|!z&x&y";
    dp[tobin("11000111")]="!(!z&x|y)|x&y";
    dp[tobin("11001000")]="!(x&z|y)";
    dp[tobin("11001001")]="!(x&z|y)|x&y&z";
    dp[tobin("11001010")]="!x&!y|!z&x";
    dp[tobin("11001011")]="!(x&z|y)|x&y";
    dp[tobin("11001100")]="!y";
    dp[tobin("11001101")]="!y|x&z";
    dp[tobin("11001110")]="!y|!z&x";
    dp[tobin("11001111")]="!y|x";
    dp[tobin("11010000")]="!(!z&y|x)";
    dp[tobin("11010001")]="!x&!y|y&z";
    dp[tobin("11010010")]="!(!z&y|x)|!z&x&y";
    dp[tobin("11010011")]="!(!z&y|x)|x&y";
    dp[tobin("11010100")]="!(!z&x|y)|!x&z";
    dp[tobin("11010101")]="!x&!y|z";
    dp[tobin("11010110")]="!(!z&x|y)|!x&z|!z&x&y";
    dp[tobin("11010111")]="!x&!y|x&y|z";
    dp[tobin("11011000")]="!x&z|!y&!z";
    dp[tobin("11011001")]="!(x&z|y)|y&z";
    dp[tobin("11011010")]="!(!x&!z&y|x&z)";
    dp[tobin("11011011")]="!x&!y|!z&x|y&z";
    dp[tobin("11011100")]="!x&z|!y";
    dp[tobin("11011101")]="!y|z";
    dp[tobin("11011110")]="!x&z|!y|!z&x";
    dp[tobin("11011111")]="!y|x|z";
    dp[tobin("11100000")]="!(x|y&z)";
    dp[tobin("11100001")]="!(x|y&z)|x&y&z";
    dp[tobin("11100010")]="!x&!y|!z&y";
    dp[tobin("11100011")]="!(x|y&z)|x&y";
    dp[tobin("11100100")]="!x&!z|!y&z";
    dp[tobin("11100101")]="!(x|y&z)|x&z";
    dp[tobin("11100110")]="!(!y&!z&x|y&z)";
    dp[tobin("11100111")]="!x&!y|!z&y|x&z";
    dp[tobin("11101000")]="!((x|y)&z|x&y)";
    dp[tobin("11101001")]="!((x|y)&z|x&y)|x&y&z";
    dp[tobin("11101010")]="!x&!y|!z";
    dp[tobin("11101011")]="!x&!y|!z|x&y";
    dp[tobin("11101100")]="!x&!z|!y";
    dp[tobin("11101101")]="!x&!z|!y|x&z";
    dp[tobin("11101110")]="!y|!z";
    dp[tobin("11101111")]="!y|!z|x";
    dp[tobin("11110000")]="!x";
    dp[tobin("11110001")]="!x|y&z";
    dp[tobin("11110010")]="!x|!z&y";
    dp[tobin("11110011")]="!x|y";
    dp[tobin("11110100")]="!x|!y&z";
    dp[tobin("11110101")]="!x|z";
    dp[tobin("11110110")]="!x|!y&z|!z&y";
    dp[tobin("11110111")]="!x|y|z";
    dp[tobin("11111000")]="!x|!y&!z";
    dp[tobin("11111001")]="!x|!y&!z|y&z";
    dp[tobin("11111010")]="!x|!z";
    dp[tobin("11111011")]="!x|!z|y";
    dp[tobin("11111100")]="!x|!y";
    dp[tobin("11111101")]="!x|!y|z";
    dp[tobin("11111110")]="!(x&y&z)";
    dp[tobin("11111111")]="!x|x";
}

int main () {
    precompute();
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        cout << dp[tobin(s)] << endl;
    }
    return 0;
}