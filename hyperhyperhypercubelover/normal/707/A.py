n = int(input().split()[0])
a = ''.join(input() for _ in range(n))
print('#Black&White' if sum(a.find(x) for x in 'CMY') == -3 else '#Color')