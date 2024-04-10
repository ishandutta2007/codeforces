from fractions import gcd

def lcm(a, b):
    return (a * b) // gcd(a, b)


if __name__ == '__main__':
    t, w, b = map(int, input().split())

    l = lcm(w, b)
    m = min(w, b)

    count = t // l
    result = count * m
    result += (m - 1) # 1 to m-1

    diff = max(count*l + m - t - 1, 0)
    result -= diff

    g = gcd(result, t)

    print('{}/{}'.format(result//g, t//g))