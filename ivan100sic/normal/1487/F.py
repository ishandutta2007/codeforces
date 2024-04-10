cache = {}

def solve(x):
    # print('enter ', x)
    if x in cache:
        return cache[x]

    cache[x] = 1000000

    rank = len(str(x))
    pw = ((10 ** rank) - 1) // 9

    q = x // pw
    if q == 0:
        rank -= 1
        pw = pw // 10
        q = x // pw

    if q <= 4:
        ans = min(q * rank + solve(x - q * pw), q * rank + (rank + 1) + solve(abs(x - (q + 1) * pw)))
    elif q == 5 or q == 6:
        ans = min( \
            q * rank + solve(x - q * pw), \
            q * rank + (rank + 1) + solve(abs(x - (q + 1) * pw)), \
            (rank + 1) + solve(10 * pw + 1 - x)
        )
    else:
        ans = (rank + 1) + solve(10 * pw + 1 - x)

    cache[x] = ans
    # print('eval ', x, ans)
    return ans

for x in range(-8, 9):
    for y in range(-8, 9):
        for z in range(-8, 9):
            t = x + 11*y + 111*z
            t = abs(t)
            c = abs(x) + 2*abs(y) + 3*abs(z)
            if t <= 111:
                if t not in cache:
                    cache[t] = c
                else:
                    cache[t] = min(cache[t], c)

print(solve(int(input())))