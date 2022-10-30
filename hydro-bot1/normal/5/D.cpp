// Hydro submission #6262c4019f31360077dbb63c@1650639873806
#include <bits/stdc++.h>
using namespace std;

double f(double v0, double vm, double a, double dis)
{
    if ((vm * vm - v0 * v0) / 2 / a > dis)
        return (-v0 + sqrt(v0 * v0 + 2 * a * dis)) / a;
    else
        return (vm - v0) / a + (dis - (vm * vm - v0 * v0) / 2 / a) / vm;
}

signed main()
{
    double a, vm, l, d_lim, v_lim, ans;
    cin >> a >> vm >> l >> d_lim >> v_lim;
    if (v_lim >= vm || v_lim * v_lim / 2 / a >= d_lim)
        ans = f(0, vm, a, l);
    else
    {
        double t_acc = sqrt((v_lim * v_lim + 2 * a * d_lim) / 2 / a / a);
        double t_pre, t_suc = f(v_lim, vm, a, l - d_lim);
        if (t_acc * a <= vm)
            t_pre = 2 * t_acc - v_lim / a;
        else
            t_pre = vm / a + (vm - v_lim) / a + (d_lim - vm * vm / 2 / a - (vm * vm - v_lim * v_lim) / 2 / a) / vm;
        ans = t_pre + t_suc;
    }
    cout << fixed << setprecision(10) << ans << endl;
}