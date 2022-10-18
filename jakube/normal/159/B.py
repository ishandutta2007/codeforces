from collections import Counter

def read_ints():
    return tuple(int(x) for x in input().split())

def parse_input(size):
    data = [read_ints() for _ in range(size)]
    by_diam = Counter(size for diam, size in data)
    by_color = Counter(data)
    return by_diam, by_color

n, m = read_ints()
pens_by_diam, pens_by_color = parse_input(n)
caps_by_diam, caps_by_color = parse_input(m)
closed = sum((pens_by_diam & caps_by_diam).values()) 
beautiful = sum((pens_by_color & caps_by_color).values()) 
print(closed, beautiful)