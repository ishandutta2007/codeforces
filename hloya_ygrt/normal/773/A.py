def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

class solution:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

def eu (a, b, sol):
    if a == 0:
        sol.x = 0
        sol.y = 1
        return b
    sol2 = solution()
    d = eu (b%a, a, sol2)
    sol.x = sol2.y - (b // a) * sol2.x
    sol.y = sol2.x
    return d


def find_any_solution (a, b, c, sol):
    g = eu(abs(a), abs(b), sol)
    if c % g != 0:
        return -1
    sol.x *= c // g
    sol.y *= c // g
    if (a < 0):
        sol.x *= -1
    if (b < 0):
        sol.y *= -1
    return g


def shift_solution (sol, a, b, cnt):
    sol.x += cnt * b
    sol.y -= cnt * a


def find_all_solution(a, b, c, minx, maxx, miny, maxy):
    sol = solution()
    g = find_any_solution(a, b, c, sol)
    if g == -1:
        return (-1, -1)

    a //= g
    b //= g

    sign_a = 1
    if a < 0:
        sign_a = -1
    sign_b = 1
    if b < 0:
        sign_b = -1

    shift_solution(sol, a, b, (minx - sol.x) // b)
    if sol.x < minx:
        shift_solution (sol, a, b, sign_b)
    if sol.x > maxx:
        return (-1, -1)
    lx1 = sol.x

    shift_solution (sol, a, b, (maxx - sol.x) // b)
    if sol.x > maxx:
        shift_solution (sol, a, b, -sign_b)
    rx1 = sol.x

    shift_solution (sol, a, b, - (miny - sol.y) // a)
    if sol.y < miny:
        shift_solution (sol, a, b, -sign_a)
    if sol.y > maxy:
        return (-1, -1)
    lx2 = sol.x

    shift_solution (sol, a, b, - (maxy - sol.y) // a)
    if sol.y > maxy:
        shift_solution (sol, a, b, sign_a)
    rx2 = sol.x

    if lx2 > rx2:
        lx2, rx2 = rx2, lx2
    lx = max (lx1, lx2)
    rx = min (rx1, rx2)

    if lx > rx:
        return (-1, -1)
    return (lx, rx)

def solve():
    s = input().split()
    x = int(s[0])
    y = int(s[1])
    p = int(s[2])
    q = int(s[3])

    # x, y, p, q = 3, 10, 1, 2
 
    if p == 0:
        if x == 0:
            return 0
        else:
            return -1
    if q == p:
        if x == y:
            return 0
        return -1
    if p * y - q * x == 0:
        return 0

    a = q - p
    b = -p
    c = p * y - q * x

    ans1, ans2 = find_all_solution(a, b, c, 0, int(10 ** 20), 0, int(10 ** 20))

    ansy1 = (p * y - q * x - (q - p) * ans1) // (-p)
    ansy2 = (p * y - q * x - (q - p) * ans2) // (-p)

    # print(x, y)

    sum1 = int(10 ** 25)
    if ans1 >= 0 and ansy1 >= 0 and (x + ans1) * q == (y + ansy1 + ans1) * p:
        sum1 = min(sum1, ans1 + ansy1)

    if ans2 >= 0 and ansy2 >= 0 and (x + ans2) * q == (y + ansy2 + ans2) * p:
        sum1 = min(sum1, ans2 + ansy2)
    if sum1 == int(10 ** 25):
        return -1
    return sum1
# print(solve())

t = int(input())
for i in range(t):
    print(solve())