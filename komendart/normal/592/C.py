def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)


t, w, b = [int(i) for i in input().split()]
mi = min(w, b)
lcm = w * b // gcd(w, b)

p = t // lcm * mi + min(mi - 1, t % lcm)
q = t
print("{0}/{1}".format(p // gcd(p, q), q // gcd(p, q)))