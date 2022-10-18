def read_numbers():
    return list(map(int, input().split()))


def f(n, a1, a2, b):
    ways = [sum(a1[:h]) + b[h] + sum(a2[h:]) for h in range(n)]
    ways.sort()
    return sum(ways[:2])


if __name__ == '__main__':
    n = int(input())
    a1 = read_numbers()
    a2 = read_numbers()
    b = read_numbers()
    print(f(n, a1, a2, b))