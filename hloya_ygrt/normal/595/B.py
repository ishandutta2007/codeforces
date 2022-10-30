def get_arr(Len):
    buff = input().split()
    a = []
    for i in range(Len):
        a.append(int(buff[i]))
    return a

base = int(1e9 + 7)
buff = input().split()
n = int(buff[0])
k = int(buff[1])
a = get_arr(n//k)
b = get_arr(n//k)
c = []

for i in range(n//k):
    ans = 0
    if (b[i] != 0):
        ans += (pow(10, k ) - 1) // a[i]
        ans -= ( (b[i] * pow(10, k - 1)) + pow(10, k - 1) - 1) // a[i]
        ans += ( ((b[i] - 1) * pow(10, k - 1)) + pow(10, k - 1) - 1) // a[i]
        ans += 1 # 00000..00
    else:
        ans = (pow( 10, k ) - 1) // a[i]
        ans -= (pow(10, k - 1) - 1) // a[i]
    c.append(ans % base)
ans = 1
for i in range(n//k):
    ans *= c[i]
    ans %= base
print(ans)