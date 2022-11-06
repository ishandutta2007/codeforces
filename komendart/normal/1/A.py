arr = [int(i) for i in raw_input().split()]
n, m, a = arr
n = n/a if n % a == 0 else n/a + 1
m = m/a if m % a == 0 else m/a + 1
print n * m