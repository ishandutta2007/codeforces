def c(n, k):
    if(k == 0 or k == n):
        return 1
    if(k < 0 or k > n):
        return 0
    return c(n - 1, k) + c(n - 1, k - 1)
a = input()
b = input()
t = a.count('+') - a.count('-') - b.count('+') + b.count('-')
k = b.count('?')
if(t % 2 != k % 2):
    print(0)
else:
    x = (t + k) / 2
    print(c(k, x) / 2 ** k)