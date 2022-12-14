/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Azat Ismagilov
 */

/**********.*****.**************************:-******-:*******************
**********......:*****************+@%@*+#@@@+.****.***********************
...------........-*+*********+%#####@@@##########*************************
********:........----------%@#####################@@-...............------
**********......:********@%#####@###################@#@=+***************::
*********.:****--******%##@#####@#######################@*+***************
********.*******:-**+@@####@#@@@#################@#########=**************
*******-*********:*@@@######@###############################=*************
*****--**********%%@##@########@#############################=:***********
****.************+##################@#@@#####################@************
***.*************%######################@@###################=***********-
*-:**************=##########@@%%%%=%@=%=%=%@################@@**********.*
.****************########%++***+++****+++=+===+++***+=%@######%*******:-**
****************+#######%+*::::::::::::***********:::::**@@###%******.:***
****************#######@%*:::::::::::::::*:*****:::::::::*@@##@*****.*****
****************######@%+*:::::::-::::::::::::::::::::::::=@##%****-******
.......-------:*######=::::::----------:::::::::::::::::::+###:**--*******
............:==:%####=:::::----:-:::::::::::::::::::::::::=@##:-.:********
************=@++*%##@::::*=%%%@@###@=***::::::::::::::::::=@#@*..*********
************=**+@+@#*:::**+++%@#@###%@%%+*::*+=======*::::*##-:**.********
*************:=%%:%*::::*+=%##%###=@@@%=*::*=%@@@%%@@#@%::+#@:****.*******
:**************==:=:::--::::*++++=%@@@%*:--*%#@####@#=+***@@%@*****.******
--**************:-*::--------::**+***:::---*+%%%%%%@@%+*::#*@%******.*****
*:-************---*::::-----------::--:---::::+++++**:::::%*%********-:***
**:.************++*:::::--------::**+------::::::::::::::*++**********--**
****.**************::::::-----::**==:-------+*:::::---:::**************:-*
*****.***********.*::::::::-:::***:*+@**::**=+*::::::::::****************-
******.*:*%@######+::::::::::::::::::++++=******::::::::******************
******:############*::::::::****::::::*+*:*:*:***::::::*******************
******#############***::*:*:*+==@@##=======:*+***:::*:********************
******#############:*+**********:*++**+**++=%=***:*::*********************
.....##############::*++**************+***:*********###+******************
***:##############@*:**+=***:::**++===++***********#####%.................
*:*###############******++=+*:::::::*:::::*::***#########=****************
**:################%*****++==++********::::*+++=##########+***************
*:%##################******++++==+=++++++++++++@############**************
######################@******+++++++++++++++++=%#############*************
########################+++++++++++++++++++++==@#############@***********.
#########################%+++++++++++++++++===%###############%********:-*
########################@=#=++++++++++++====%@##################******-**/

#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endd "\n"; return 0;
#define all(v) v.begin(), v.end()

using namespace std;

const int MAXN = 1e5;
const int INF = 1e18;
const int MOD = 1e9 + 7;

class TaskB {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n, m;
        in >> n >> m;
        n--;
        set<int> anses;
        pr<int, int> a[m];
        for (int i = 0; i < m; i++) {
            in >> a[i].fs >> a[i].sc;
            a[i].fs--;
            a[i].sc--;
        }
        for (int i = 1; i <= 1000; i++) {
            bool prav = 1;
            for (int j = 0; j < m; j++) {
                if ((a[j].fs / i) != a[j].sc) {
                    prav = 0;
                }
            }
            if (prav) {
                anses.insert(n / i + 1);
            }
        }
        if (len(anses) == 1) {
            out << *anses.begin();
        } else {
            out << -1;
        }
    }
};


main() {
    ios_base::sync_with_stdio(0);
    TaskB solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}