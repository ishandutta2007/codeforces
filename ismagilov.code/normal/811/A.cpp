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
#define endl "\n"
#define endd "\n"; return 0;
#define all(v) v.begin(), v.end()

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

using namespace std;

const int MAXN = 1e5;
const int INF = 1e18;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    int tek = 1;
    while(1){
    	if (a >= tek){
    		a -= tek;
    		tek++;
    	}
    	else{
    		cout << "Vladik" << endd;
    	}
    	if (b >= tek){
    		b -= tek;
    		tek++;
    	}
    	else{
    		cout << "Valera" << endd;
    	}
    }
}